'use strict';

let AWS = require('aws-sdk');
let config = require('./config');
let producer = require('./sample_producer');

process.env.AWS_PROFILE = "saml";

let kinesis = new AWS.Kinesis({region : config.kinesis.region});
producer(kinesis, config.sampleProducer).run();