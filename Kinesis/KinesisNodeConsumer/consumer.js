'use strict';

const kcl = require('aws-kcl');
const logger = require('./util/logger');
const fs = require('fs');

let recordProcessor = () => {
  let log = logger().getLogger('recordProcessor');
  let shardId;

  return {
    initialize: (initializeInput, completeCallback) => {
      shardId = initializeInput.shardId;
      log.info(`Record processor initialized: ${JSON.stringify(initializeInput, null, 2)}`);
      completeCallback();
    },

    /*
      processRecordsInput contains: {
        'checkPointer': '<Object>',
        'millisBehindLatest': '...',
        'records': '[<Object>]'
      }
      Each record in the records array is of format: {
        'action': '...',
        'approximateArrivalTimestamp': '...'
        'data': '...',
        'partitionKey': '...',
        'sequenceNumber': '...',
        'subSequenceNumber': '...'
      }
    */
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
        log.info(`Processing record (ShardID: ${shardId}, SequenceNumber: ${sequenceNumber}, PartitionKey: ${partitionKey}). Data: ${JSON.stringify(data, null, 2)}`);
        writeToReconFile(shardId + '-' + sequenceNumber);
      }

      // If no sequence number, return -- we cannot checkpoint
      if (!sequenceNumber) {
        completeCallback();
        return;
      }

      // If checkpointing, completeCallback should only be called once checkpoint is complete.
      processRecordsInput.checkpointer.checkpoint(sequenceNumber, (err, sequenceNumber) => {
        // log.info(`Checkpoint successful. ShardID: ${shardId}, SequenceNumber: ${sequenceNumber}`);
        completeCallback();
      });
    },

    leaseLost: (leaseLostInput, completeCallback) => {
      // log.info(`Lease was lost for ShardId: ${shardId}`);
      completeCallback();
    },

    shardEnded: (shardEndedInput, completeCallback) => {
      // log.info(`Shard ended`);
      shardEndedInput.checkpointer.checkpoint((err) => {
        completeCallback();
      });
    },

    shutdownRequested: (shutdownRequestedInput, completeCallback) => {
      // log.info(`Shutdown requested`);
      // Checkpoint progress -- if no sequence number is provided, KCL assumes that all records have been processed
      shutdownRequestedInput.checkpointer.checkpoint((err) => {
        completeCallback();
      });
    }
  };
}

let writeToReconFile = (data) => {
  fs.writeFileSync('./recon.txt', data + '\n', { flag: 'a+' }, err => {
    logger.log(`Error writing to recon file: ${e}`);
  });
}

let cleanUpArtifacts = () => {
  const logsDirPath = './app-logs';
  fs.readdirSync(logsDirPath).forEach(f => fs.rmSync(`${logsDirPath}/${f}`, { force: true }));
  fs.rmSync('recon.txt', { force: true });
}

cleanUpArtifacts();

kcl(recordProcessor()).run();