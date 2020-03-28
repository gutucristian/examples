#include "buffer.hpp"
#include <assert.h>
#include "Simulator.hpp"
#include <iostream>

void Buffer::addTarget(Component* c2)
{
   _target = c2;
   c2->setFeed(this);
   //std::cout << "feed for " << c2->getName() << " is " << this->getName() << std::endl;
}

std::ostream& FIFO::print(std::ostream& os)  const
{
   double avg = 0;
   for (double x: waitTimes) {
      avg += x;
   }
   avg /= waitTimes.size();
   
   double avgQsize = 0;
   for (double x: queueSizes) {
     avgQsize += x;
   }
   avgQsize /= queueSizes.size();

   assert(_target != nullptr);
   //return os <<  _name << "=FIFO(target = " << _target->getName() << ")" << " | " << _name 
   // << "Queue Len(" << arrivals << ") Avg. wait time(" << avg << ") Avg. Queue Size(" << avgQsize << ")";
   return os <<  _name << "-Queue Len(" << arrivals << ") : " << avgQsize << "\n" << _name << "-wait Time(" << waitTimes.size() << ") : " << avg;
}


