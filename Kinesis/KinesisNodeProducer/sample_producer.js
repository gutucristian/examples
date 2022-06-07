'use strict';

let logger = require('./util/logger');

let sampleProducer = (kinesis, config) => {
  let log = logger().getLogger('sampleProducer');

  let _createStreamIfNotCreated = (callback) => {
    let params = {
      ShardCount : config.shards,
      StreamName : config.stream
    };

    kinesis.createStream(params, (err, data) => {
      if (err) {
        if (err.code !== 'ResourceInUseException') {
          callback(err);
          return;
        } else {
          log.info(`${config.stream} stream is already created. Re-using it.`);
        }
      } else {
        log.info(`${config.stream} stream doesn't exist. Created a new stream with that name..`);
      }

      // Poll to make sure stream is in ACTIVE state before start pushing data.
      _waitForStreamToBecomeActive(callback);
    });
  }

  let _waitForStreamToBecomeActive = (callback) => {
    kinesis.describeStream({StreamName : config.stream}, (err, data) => {
      if (!err) {
        log.info(`Current status of the stream is ${data.StreamDescription.StreamStatus}`);
        if (data.StreamDescription.StreamStatus === 'ACTIVE') {
          callback(null);
        } else {
          setTimeout(
            () => { _waitForStreamToBecomeActive(callback); },
            1000 * config.waitBetweenDescribeCallsInSeconds
          );
        }
      }
    });
  }

  let _writeToKinesis = () => {
    let currTime = new Date().getMilliseconds();
    let sensor = 'sensor-' + Math.floor(Math.random() * 100000);
    let reading = Math.floor(Math.random() * 1000000);

    let record = JSON.stringify({
      time : currTime,
      sensor : sensor,
      reading : reading
    });

    let recordParams = {
      Data : record,
      PartitionKey : sensor,
      StreamName : config.stream
    };

    kinesis.putRecord(recordParams, (err, data) => {
      if (err) {
        log.error(err);
      } else {
        log.info(`Successfully sent data to Kinesis: ${JSON.stringify(data, null, 2)}`);
      }
    });
  }

  return {
    run: () => {
       _createStreamIfNotCreated((err) => {
        if (err) {
          log.error(`Error creating stream: ${err}`);
          return;
        }
        let count = 0;
        while (count < 2) {
          setTimeout(_writeToKinesis, 1000);
          count++;
        }
      });
    }
  };
}

module.exports = sampleProducer;
