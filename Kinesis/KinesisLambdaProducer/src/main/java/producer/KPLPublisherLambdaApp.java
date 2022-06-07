package producer;

import com.amazonaws.services.kinesis.producer.*;
import com.amazonaws.services.lambda.runtime.Context;
import com.amazonaws.services.lambda.runtime.RequestHandler;
import com.amazonaws.services.lambda.runtime.LambdaLogger;

import com.google.common.util.concurrent.FutureCallback;
import com.google.common.util.concurrent.ListenableFuture;
import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import models.Response;
import utils.Utils;

import java.nio.ByteBuffer;
import java.nio.charset.StandardCharsets;
import java.util.Map;
import java.util.concurrent.*;

public class KPLPublisherLambdaApp implements RequestHandler<Map<String,String>, String>{
    private final String AWS_REGION = "us-east-1";
    private final String STREAM_NAME = "foobar";

    private LambdaLogger logger;

    Gson gson = new GsonBuilder().setPrettyPrinting().create();

    @Override
    public String handleRequest(Map<String,String> event, Context context)
    {
        String response;

        logger = context.getLogger();

        // log execution details
        logger.log("ENVIRONMENT VARIABLES: " + gson.toJson(System.getenv()));
        logger.log("CONTEXT: " + gson.toJson(context));

        // process event
        logger.log("EVENT: " + gson.toJson(event));
        logger.log("EVENT TYPE: " + event.getClass());

        try {
            response = gson.toJson(publishEvent(event));
        } catch (InterruptedException | ExecutionException e) {
            response = gson.toJson(new Response("Event could not be published: " + e.getMessage(), null, null, STREAM_NAME));
        }

        return response;
    }

    private KinesisProducer getProducer() {
        KinesisProducerConfiguration producerConfig = new KinesisProducerConfiguration()
                .setRegion(AWS_REGION)
                .setRecordMaxBufferedTime(3000)
                .setMaxConnections(1)
                .setRequestTimeout(60000);

        // Instantiate KPL client
        KinesisProducer producer = new KinesisProducer(producerConfig);

        Runtime.getRuntime().addShutdownHook(new Thread(() -> {
            if (producer != null) {
                logger.log("Shutting down program");
                producer.flush();
            }
        }, "producer-shutdown"));

        return producer;
    }

    public Response publishEvent(Map<String,String> event) throws InterruptedException, ExecutionException {
        final FutureCallback<UserRecordResult> callback = new FutureCallback<UserRecordResult>() {
            @Override
            public void onFailure(Throwable t) {
                // If we see any failures, we will log them.
                if (t instanceof UserRecordFailedException) {
                    int attempts = ((UserRecordFailedException) t).getResult().getAttempts().size() - 1;
                    Attempt last = ((UserRecordFailedException) t).getResult().getAttempts().get(attempts);
                    if (attempts > 1) {
                        Attempt previous = ((UserRecordFailedException) t).getResult().getAttempts().get(attempts - 1);
                        logger.log(String.format(
                                "Record failed to put - %s : %s. Previous failure - %s : %s",
                                last.getErrorCode(), last.getErrorMessage(),
                                previous.getErrorCode(), previous.getErrorMessage()));
                    } else {
                        logger.log(String.format(
                                "Record failed to put - %s : %s.",
                                last.getErrorCode(), last.getErrorMessage()));
                    }

                } else if (t instanceof UnexpectedMessageException) {
                    logger.log("Record failed to put due to unexpected message received from native layer: " + t);
                }
                logger.log("Exception during put: " + t);
            }

            @Override
            public void onSuccess(UserRecordResult result) {
                logger.log(String.format("Record successfully published to the stream." +
                                "ShardId: %s, Sequence Number: %s, NO. of attempts: %s",
                        result.getShardId(), result.getSequenceNumber(),
                        result.getAttempts().size()));
            }
        };

        KinesisProducer producer = getProducer();

        // final ExecutorService callbackThreadPool = Executors.newCachedThreadPool();

        ByteBuffer data = ByteBuffer.wrap(gson.toJson(event).getBytes(StandardCharsets.UTF_8));

        String partitionKey = Utils.getRandomString();

        logger.log(String.format("Write record to stream %s with partition key %s", STREAM_NAME, partitionKey));

        ListenableFuture<UserRecordResult> f = producer.addUserRecord(STREAM_NAME, partitionKey, data);

        // Blocks
        UserRecordResult result = f.get();

        Response response = new Response("Published record to stream", result.getShardId(), result.getSequenceNumber(), STREAM_NAME);

        logger.log(gson.toJson(response));

        return response;

        // If the Future is complete by the time we call addCallback, the callback will be invoked immediately.
        // Futures.addCallback(f, callback, callbackThreadPool);
    }
}