package models;

public class Response {
    String message;
    String sequenceNumber;
    String shard;
    String stream;

    public Response(String message, String sequenceNumber, String shard, String stream) {
        this.message = message;
        this.sequenceNumber = sequenceNumber;
        this.shard = shard;
        this.stream = stream;
    }
}
