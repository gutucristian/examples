#ifndef __EVENT_H
#define __EVENT_H

#include <memory>
#include <iostream>
#include "component.hpp"

class Event {
  public:
    Component* target;
    double time;
    virtual std::ostream& print(std::ostream& os) const {};
    Event(double time, Component *target): time(time), target(target) {};
    virtual ~Event();
    double when() const { return time;};
    virtual void process(double time, int clientId) {};
};

struct CompareEvent {
  bool operator() (std::shared_ptr<Event> a, std::shared_ptr<Event> b) {
    return a->when() > b->when();
  } 
};

class EnterQueue: public Event {
  public:
    EnterQueue(double time, Component *target): Event(time, target) {};
    void process(double time, int clientId);
    virtual ~EnterQueue();
};

class LeaveQueue: public Event {
  public:
    LeaveQueue(double time, Component *target): Event(time, target) {};
    void process(double time, int clientId);
    virtual ~LeaveQueue();
};
  
#endif

