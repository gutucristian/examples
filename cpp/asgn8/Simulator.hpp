#ifndef __SIMULATOR_H
#define __SIMULATOR_H

#include <iostream>
#include <istream>
#include <map>
#include <list>
#include <functional>
#include <queue>

#include "component.hpp"
#include "event.hpp"
#include "server.hpp"

namespace Generator {
   class Generator;
}

class Simulator {
   std::priority_queue<std::shared_ptr<Event>, 
                       std::vector<std::shared_ptr<Event>>,
                       CompareEvent> _pq;
   double _time;
   int _lastEvt;
   int _lastCli;
   double  _horizon;
   // Type for a builder function
   typedef std::function<void(std::istream&,const std::string& name)> buildFun;   
   std::map<std::string,buildFun> _builders; // map of builders (poly-construction)   
   std::map<std::string,Component*> _cps;    // map of components
   std::list<Generator::Generator*> _gens;    // all the generators.
   std::list<Server*> _servers;
   // Simulation data structures
   void addComponent(const std::string& key,Component* c);
   bool hasComponent(const std::string& key) const;
   Component* getComponent(const std::string& key);
public:
   Simulator();
   double horizon() const { return _horizon;}
   void read(const char* fn);      
   void run(double h);
   friend std::ostream& operator<<(std::ostream& os,const Simulator& s);
};

#endif
