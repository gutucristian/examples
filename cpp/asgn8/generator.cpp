#include "generator.hpp"
#include "Simulator.hpp"
#include "buffer.hpp"
#include <math.h>
#include <stdlib.h>

namespace Generator {
   Poisson::Poisson(const std::string& n,double r)
      : Generator(n),
        _rd(),
        _gen(_rd()),
        _dis(0.0,1.0)
   {
      _lambda = r;
      _lastArrival = 0.0;
   }
   
   std::ostream& Poisson::print(std::ostream& os)  const
   {
      //return os <<  _name << "=Poisson(" << _lambda << ",target=" << _target->getName() << ")";
      return os;
   }
   double Poisson::genInterArrival()
   {
      double rnd = _dis(_gen);
      return - logf(1.0f - rnd) / _lambda;
   }
   double Poisson::nextTime()
   {
      _lastArrival += genInterArrival();
      return _lastArrival;
   }
}

