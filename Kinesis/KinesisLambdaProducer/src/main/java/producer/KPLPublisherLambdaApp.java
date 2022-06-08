package producer;

import com.amazonaws.services.kinesis.producer.*;
import com.amazonaws.services.lambda.runtime.Context;
import com.amazonaws.services.lambda.runtime.RequestHandler;
import com.amazonaws.services.lambda.runtime.LambdaLogger;

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
    private LambdaLogger logger;

    Gson gson = new GsonBuilder().setPrettyPrinting().create();

    @Override
    public String handleRequest(Map<String,String> event, Context context)
    {
        String response;

        logger = context.getLogger();

        // Log execution context
        logger.log("Execution context: " + gson.toJson(context));

        // Log record to be published
        logger.log("Publish event: " + gson.toJson(event));

        response = gson.toJson(publishEvent(event));

        logger.log(gson.toJson(response));

        return response;
    }

    private KinesisProducer getProducer() {
        KinesisProducerConfiguration producerConfig = new KinesisProducerConfiguration()
                .setRegion(Utils.AWS_REGION)
                .setRecordMaxBufferedTime(3000)
                .setMaxConnections(1)
                .setRequestTimeout(60000);

        // Instantiate KPL client
        KinesisProducer producer = new KinesisProducer(producerConfig);

        Runtime.getRuntime().addShutdownHook(new Thread(() -> {
            logger.log("Shutting down producer");
            producer.flush();
        }, "producer-shutdown"));

        return producer;
    }

    public Response publishEvent(Map<String,String> event) {
        KinesisProducer producer = getProducer();

        ByteBuffer data = ByteBuffer.wrap(gson.toJson(event).getBytes(StandardCharsets.UTF_8));

        String partitionKey = Utils.getRandomString();

        ListenableFuture<UserRecordResult> f = producer.addUserRecord(Utils.STREAM_NAME, partitionKey, data);

        Response response;

        try {
            UserRecordResult result = f.get(); // Waits for computation to complete and then retrieves result
            response = new Response("Published record to stream", result.getShardId(), result.getSequenceNumber(), Utils.STREAM_NAME);
        } catch (InterruptedException | ExecutionException e) {
            response = new Response("Event could not be published: " + e.getMessage(), null, null, Utils.STREAM_NAME);
        }

        logger.log(gson.toJson(response));

        return response;
    }
}