## Kinesis Client Library (KCL) Overview

KCL is used to build applications that process data from your Kinesis data stream.

KCL is a Java library. Support for other languages is provided via a multi-language interface called the *MultiLangDeamon*.

The deamon is Java-based and runs in the background when you are using a KCL language other than Java.

Therefore, for a Node.js consumer, you'd still need Java installed on the system.

The daemon launches the user-defined program as a sub-process and then communicates with this sub-process over `stdin`/`stdout` using a protocol. This allows KCL to be language-agnostic while providing identical features and same parallel processing model across all languages.

## Terminology and Concepts

### Kinesis Data Stream

A Kinesis data stream is a set of shards (i.e., partitions). Each shard has a **sequence of data records**. Each data record has a sequence number that is assigned by Kinesis Data Streams.

### Data Record

A **data record** is the unit of data stored in a Kinesis data stream. Data records are composed of a sequence number, a partition key, and a data blob, which is an immutable sequence of bytes. A data blob can be up to 1 MB.

### Capacity Mode

Capacity mode determines how capacity is managed and how you are charged for the usage of your data stream.

The two capacity modes are: **on-demand** mode and **provisioned** mode.

With the on-demand mode, Kinesis Data Streams automatically manages the shards in order to provide the necessary throughput.

With the provisioned mode, you must specify the number of shards for the data stream. The total capacity of
a data stream is the sum of the capacities of its shards.You can increase or decrease the number of shards
in a data stream as needed.

### Retention period

The *retention period* is the length of time that data records are accessible after they are added to the stream.

Default is 24 hours and can be increased up to 8760 hours (365 days).

### Shard

A shard is a uniquely identified sequence of data records in a stream. A stream is composed of one or more shards, each of which provides a fixed unit of capacity.

### Partition Key

A partition key is used to group data by shard within a stream. Partition keys are Unicode strings, with a maximum length limit of 256 characters for each key. An MD5 hash function is used to map partition keys to a shard. When an application puts data into a stream, it must specify a partition key.

### Sequence number

Each data record has a sequence number that is unique per partition-key within its shard. Kinesis Data Streams assigns the sequence number after you write to the stream. Sequence numbers for the same partition key generally increase over time.

## Consumer

A consumer must implement a `recordProcessor` function which in turn contains the functions:
- `initialize`, 
- `processRecords`
- `shutdown` 

### `initialize`

`initialize: function(initializeInput, completeCallback)`

The KCL calls the `initialize` function when the record processor starts.

This record processor processes **only** the shard ID passed as `initializeInput.shardId`. And, typically, the reverse is also true: this shard is processed only by this record processor.

However, the consumer should account for the possibility that a data record might be processed more than one time.

This is because Kinesis Data Streams has **at least once** semantics, meaning that every data record from a shard is processed at least one time by a worker in your consumer.

### `processRecords`

`processRecords: function(processRecordsInput, completeCallback)`

KCL calls this function with input that contains a **list** of **data records** from the shard specified to the `initialize` function.

The record processor that you implement processes the data in these records according to the semantics of your consumer (e.g., perform some transformation and write the result in an S3 bucket).

Each record exposes a dictionary with the following key-value pairs to access the record's data, sequence number, and partition key:

```
record.data
record.sequenceNumber
record.partitionKey
```

Kinesis Data Streams require the record processor to keep track of the records that have already been processed in a shard.

KCL takes care of this tracking with a `checkpointer` object passed as `processRecordsInput.checkpointer`.

The record processor calls `checkpointer.checkpoint` function to inform KCL how far it has progressed in processing the records in the shard.

If a worker fails, the KCL uses this information when you restart the processing of the shard so that it continues from the last known processed record.

If you don't pass the sequence number to the checkpoint function, the KCL assumes that the call to checkpoint means that all records have been processed, up to the last record that was passed to the record processor.

Therefore, the record processor should **only** call `checkpoint` after it has processed all the records in the list that was passed to it.

Record processors do not need to call `checkpoint` on each call to `processRecords`.

A processor could, for example, call checkpoint on every third call, or some event external to your record processor, such as a custom verification/validation service you've implemented.

You can optionally specify the exact sequence number of a record as a parameter to checkpoint. In this case, the KCL assumes that all records have been processed up to that record only.

### `shutdown`

`shutdown: function(shutdownInput, completeCallback)`

KCL calls the `shutdown` function when processing ends which is true in one of two cases:
1. `shutdownInput.reason` is `TERMINATE`
2. `shutdownInput.reason` is `ZOMBIE`

Processing ends when the record processor does not receive any further records from the shard, because either the shard was split or merged, or the stream was deleted.

The KCL also passes a `shutdownInput.checkpointer` object to shutdown.

If the shutdown reason is `TERMINATE`, you should make sure that the record processor has finished processing any data records, and then call the `checkpoint` function on this interface.

### Worker

Worker refers to the high level class that a KCL consumer application instance uses to start processing data.

**Important:** each KCL consumer application instance has one "worker".

The worker initializes and oversees various tasks, including:
- syncing shard and lease information
- tracking shard assignments 
- processing data from the shards

A worker provides KCL with the configuration information for the consumer application, such as the name of the data stream whose data records this KCL consumer application is going to process and the AWS credentials that are needed to access this data stream. The worker also kick starts that specific KCL consumer application instance to deliver data records from the data stream to the record processors.

### Lease

Data that defines the **binding between a worker and a shard**. Leases are used to partition data record processing across a fleet of workers. By default, a worker can hold one or more leases (subject to the value of the `maxLeasesForWorker` variable) at the same time.

### Lease table

A unique Amazon DynamoDB table that is used to keep track of the shards in a KDS that are being leased and processed by the workers of the KCL consumer application.

https://docs.aws.amazon.com/streams/latest/dev/shared-throughput-kcl-consumers.html#shared-throughput-kcl-consumers-overview

### Record processor

The logic that defines how your KCL consumer application processes the data that it gets from the data streams. At runtime, a KCL consumer application instance instantiates a **worker**, and this worker instantiates one record processor for every shard to which it holds a lease.

## To Run (dev060 broker 1)

```
scl enable rh-nodejs14 bash
export {http,https}_proxy="http://$XID:$PASS@proxy:8080/"
python3 /prustaff/<XID>/getawscreds_scripts-master/getawscreds/cli.py
node ./kcl-bootstrap.js --java /usr/bin/java -l ./logback.xml -e -p ./sample.properties > /dev/null 2>&1 &
```

At runtime, a KCL consumer application instance instantiates a worker, and this **worker instantiates one record processor for every shard to which it holds a lease**. Each record processor runs in parallel within the same process.

If you want multiple workers (i.e., consumer applications) to process same stream, then workerId must be different for each worker but applicationName and streamName need to be same for both.

This way if your stream has four shards and you have two workers

Worker 1 will process shard 1 and 2 in parallel (will spawn a record processor for each shard)
Worker 2 will process shard 3 and 4 in parallel (will spawn a record processor for each shard)

## Misc 

`&`: to send command in the background -- so we can interact with shell and start more consumers

`jobs`: to see a list of running background jobs

`kill -9 %<job-num>`: to kill a background job

`ps -e | grep node`: to list running `node` processes

`kill -9 <PID>`: send `SIGKILL` signal to process

## References

- https://github.com/awslabs/amazon-kinesis-client-nodejs
- https://docs.aws.amazon.com/streams/latest/dev/kinesis-record-processor-implementation-app-nodejs.html
- https://docs.aws.amazon.com/streams/latest/dev/shared-throughput-kcl-consumers.html#shared-throughput-kcl-consumers-overview
- https://docs.aws.amazon.com/streams/latest/dev/key-concepts.html
- https://stackoverflow.com/questions/48399903/what-is-partition-key-in-aws-kinesis-all-about
- https://stackoverflow.com/questions/49728807/trim-horizon-vs-latest
