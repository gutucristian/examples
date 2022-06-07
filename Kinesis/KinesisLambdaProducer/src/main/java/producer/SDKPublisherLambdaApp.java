package producer;

import com.amazonaws.services.lambda.runtime.Context;
import com.amazonaws.services.lambda.runtime.LambdaLogger;
import com.amazonaws.services.lambda.runtime.RequestHandler;
import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import models.Response;
import software.amazon.awssdk.core.SdkBytes;
import software.amazon.awssdk.services.kinesis.KinesisClient;
import software.amazon.awssdk.services.kinesis.model.KinesisException;
import software.amazon.awssdk.services.kinesis.model.PutRecordRequest;
import software.amazon.awssdk.services.kinesis.model.PutRecordResponse;
import utils.Utils;

import java.nio.charset.StandardCharsets;
import java.util.Map;

public class SDKPublisherLambdaApp implements RequestHandler<Map<String,String>, String> {
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

        response = gson.toJson(publishEvent(event));

        return response;
    }

    public Response publishEvent(Map<String,String> event) {
        logger.log("Publish event: " + gson.toJson(event));

        // Service client for accessing Kinesis
        KinesisClient client = KinesisClient.builder().build();

        // Convert event data to byte array
        byte[] data = gson.toJson(event).getBytes(StandardCharsets.UTF_8);

        // Generate random partition key -- Kinesis uses this to hash & determine what shard event will go into
        String partitionKey = Utils.getRandomString();

        // Represents the input for PutRecord
        PutRecordRequest.Builder builder = PutRecordRequest.builder()
                .partitionKey(partitionKey)
                .streamName(STREAM_NAME)
                .data(SdkBytes.fromByteArray(data));

        // Build put record request
        PutRecordRequest putRecordRequest = builder.build();

        Response response;

        try {
            // Submit put record request
            PutRecordResponse putRecordResponse = client.putRecord(putRecordRequest);

            response = new Response(
                    "Published record to stream",
                    putRecordResponse.sequenceNumber(),
                    putRecordResponse.shardId(), STREAM_NAME
            );

            return response;
        } catch (KinesisException e) {
            response = new Response("Event could not be published: " + e.getMessage(),
                    null,
                    null,
                    STREAM_NAME
            );
        }

        logger.log(gson.toJson(response));

        return response;
    }
}
