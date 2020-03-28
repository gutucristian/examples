#include "event.hpp"
#include "buffer.hpp"
#include "client.hpp"
#include "server.hpp"

Event::~Event() {};

void EnterQueue::process(double time, int clientId) {
  std::shared_ptr<Client> c(new Client(target, time, clientId));
  Buffer *buf = dynamic_cast<Buffer*>(target);
  buf->queue.push(c);
  buf->arrivals++;
}

EnterQueue::~EnterQueue() {}


void LeaveQueue::process(double time, int clientId) {
  std::shared_ptr<Client> c;
  if (target->getType() == "exit") {
    // do nothing
  } else if (target->getType() == "disp") {
    Dispatcher *s = dynamic_cast<Dispatcher*>(target);
    double x = s->sampleServiceTime();
    int i = 0;
    for (auto it = s->_rules.begin(); it != s->_rules.end(); it++) {
      if (x >= i && x < i+it->second) {
        c = std::make_shared<Client>(it->first, time, clientId);
        if (it->first->getType() != "exit") {
          Buffer *buf = dynamic_cast<Buffer*>(c->target);
          buf->queue.push(c);
          buf->arrivals++;
        }
        break;
      }
      i += it->second;
    }
  } else if (target->getType() == "buf") {
    c = std::make_shared<Client>(target, time, clientId);
    Buffer *buf = dynamic_cast<Buffer*>(target);
    buf->queue.push(c);
    buf->arrivals++;
  }
}

LeaveQueue::~LeaveQueue() {}
