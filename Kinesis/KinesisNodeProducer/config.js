'use strict';

var config = module.exports = {
  kinesis : {
    region : 'us-east-1'
  },

  sampleProducer : {
    stream : 'isg-push-test-stream',
    shards : 1,
    waitBetweenDescribeCallsInSeconds : 5
  }
};