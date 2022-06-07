'use strict';

let kcl = require('aws-kcl');
let logger = require('./util/logger');

let recordProcessor = () => {
  let log = logger().getLogger('recordProcessor');
  let shardId;

  return {
    initialize: (initializeInput, completeCallback) => {
      shardId = initializeInput.shardId;
      log.info(`Record processor initialized: ${JSON.stringify(initializeInput, null, 2)}`);
      completeCallback();
    },

    processRecords: (processRecordsInput, completeCallback) => {
      // If no records to process, return
      if (!processRecordsInput || !processRecordsInput.records) {
        completeCallback();
        return;
      }

      let records = processRecordsInput.records;
      let record, data, sequenceNumber, partitionKey;

      // Process records
      for (let i = 0 ; i < records.length ; ++i) {
        record = records[i];
        data = new Buffer(record.data, 'base64').toString();
        sequenceNumber = record.sequenceNumber;
        partitionKey = record.partitionKey;
        log.info(`Processing record (ShardID: ${shardId}, SequenceNumber: ${sequenceNumber}, PartitionKey: ${partitionKey}): ${JSON.stringify(data, null, 2)}`);
      }

      // If no sequence number, return -- we cannot checkpoint
      if (!sequenceNumber) {
        completeCallback();
        return;
      }

      // If checkpointing, completeCallback should only be called once checkpoint is complete.
      processRecordsInput.checkpointer.checkpoint(sequenceNumber, (err, sequenceNumber) => {
        log.info(`Checkpoint successful. ShardID: ${shardId}, SequenceNumber: ${sequenceNumber}`);
        completeCallback();
      });
    },

    leaseLost: (leaseLostInput, completeCallback) => {
      log.info(`Lease was lost for ShardId: ${shardId}`);
      completeCallback();
    },

    shardEnded: (shardEndedInput, completeCallback) => {
      log.info(`Shard ended`);
      shardEndedInput.checkpointer.checkpoint((err) => {
        completeCallback();
      });
    },

    shutdownRequested: (shutdownRequestedInput, completeCallback) => {
      log.info(`Shutdown requested`);
      // Checkpoint progress -- if no sequence number is provided, KCL assumes that all records have been processed
      shutdownRequestedInput.checkpointer.checkpoint((err) => {
        completeCallback();
      });
    }
  };
}

kcl(recordProcessor()).run();