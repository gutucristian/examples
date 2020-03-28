#ifndef __GENERATOR_H
#define __GENERATOR_H

#include <random>
#include "component.hpp"

class Simulator;

namespace Generator {
   class Generator :public Component {
   protected:
      Component* _target;
      void addTarget(Component* c2) { _target = c2;}
   public:
      Generator(const std::string& n) : Component(n) {}
      ~Generator() {}
      Component* getTarget() { return _target;}
   };
   
   class Poisson :public Generator {
      double              _lambda;
      std::random_device      _rd;
      std::mt19937           _gen;
      std::uniform_real_distribution<> _dis;
      double         _lastArrival;
      std::ostream& print(std::ostream& os)  const;
      double genInterArrival();
   public:
      double nextTime();
      Poisson(const std::string& n,double r);
      ~Poisson() {}
   };
};

#endif
