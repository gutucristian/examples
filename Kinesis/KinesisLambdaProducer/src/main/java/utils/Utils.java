package utils;

import java.util.Random;

public class Utils {
    public final static String AWS_REGION = "us-east-1";
    public final static String STREAM_NAME = "test-stream";

    public static String getRandomString() {
        final String SALT_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
        StringBuilder salt = new StringBuilder();
        Random rnd = new Random();
        while (salt.length() < 18) { // length of the random string.
            int index = (int) (rnd.nextFloat() * SALT_CHARS.length());
            salt.append(SALT_CHARS.charAt(index));
        }
        return salt.toString();
    }
}
