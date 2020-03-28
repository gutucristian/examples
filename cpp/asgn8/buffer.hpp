#ifndef __BUFFER_H
#define __BUFFER_H

#include <queue>
#include <iostream>
#include "component.hpp"
#include "client.hpp"
#include <memory>
#include <vector>

class Buffer: public Component {
protected:
   Component* _target;
   void addTarget(Component* c2);
public:
   std::vector<double> waitTimes;
   std::vector<double> queueSizes;
   int arrivals = 0;
   virtual void addWaitTime(double t) {};
   virtual void addQueueSize(double t) {};
   std::string getType() {};
   std::queue<std::shared_ptr<Client>> queue;
   Buffer(const std::string& n) : Component(n) {  _target = nullptr;}
   virtual ~Buffer() {}
   Component* getTarget() { return _target;}
};

class FIFO : public Buffer {
protected:
   std::ostream& print(std::ostream& os)  const;
public:
   void addWaitTime(double t) { waitTimes.push_back(t);}
   virtual void addQueueSize(double t) { queueSizes.push_back(t);}
   std::string getType() {return "buf";}
   FIFO(const std::string& n) : Buffer(n)  {}
   ~FIFO() {}
};
  
#endif
