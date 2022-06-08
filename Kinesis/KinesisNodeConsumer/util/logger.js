'use strict';

var log4js = require('log4js');



function logger() {
  var logDir = process.env.NODE_LOG_DIR !== undefined ? process.env.NODE_LOG_DIR : './app-logs/';

  var config = {
    appenders: {
      default: {
        "type": "file",
        "filename": logDir + "/" + process.pid + ".application.log",
        "pattern": "-yyyy-MM-dd",
        "layout": {
          "type": "pattern",
          "pattern": "%d (PID: %x{pid}) %p %c - %m",
          "tokens": {
            "pid": function () { return process.pid; }
          }
        }
      },
    },
    categories: {
      default: { appenders: ['default'], level: 'info' },
    }
  };

  log4js.configure(config, {});

  return {
    getLogger: function (category) {
      return log4js.getLogger(category);
    }
  };
}

module.exports = logger;