'use strict';

var log4js = require('log4js');

function logger() {

  let config = {
    appenders: {
      file: { type: 'file', filename: 'all-the-logs.log' },
      server: { type: 'tcp-server', host: '0.0.0.0' },
    },
    categories: {
      default: { appenders: ['file'], level: 'info' }
    }
  }

  log4js.configure(config, {});

  return {
    getLogger: function (category) {
      return log4js.getLogger(category);
    }
  };
}

module.exports = logger;
