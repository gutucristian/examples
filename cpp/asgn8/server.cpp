#include "server.hpp"
#include "Simulator.hpp"
#include "buffer.hpp"
#include <assert.h>
#include <random>

Server::Server(const std::string& n)
   : Component(n)
{
   _target = nullptr;   
}

ServerExponential::ServerExponential(const std::string& n,double r)
   : Server(n),
     _rate(r),
     _rd(),
     _gen(_rd()),
     _dis(r)
{
}   

std::ostream& ServerExponential::print(std::ostream& os)  const
{
   //return os << _name <<   "=ServerExp(" << _rate << ','
   //          << "target=" << _target->getName() << ")";
   double avg = 0;
   for (auto x: processingTimes)
     avg += x;
   avg /= processingTimes.size();
   return os << _name << "-service time(" << processingTimes.size() << ") : " << avg;
}

double ServerExponential::sampleServiceTime() 
{
   double n = _dis(_gen);
   processingTimes.push_back(n);  
   return n;
}

std::string ServerExponential::getType() 
{
   return "exp";
}

ServerNormal::ServerNormal(const std::string& n,double m,double d)
   : Server(n),
     _mean(m),
     _deviation(d)
{
}   

std::ostream& ServerNormal::print(std::ostream& os)  const
{
   return os << _name <<   "=ServerNormal(" << _mean << ',' << _deviation
             << ',' << "target=" << _target->getName() << ")";
}

double ServerNormal::sampleServiceTime() 
{
   std::default_random_engine generator;
   std::normal_distribution<double> distribution(_mean, _deviation);
   double number = distribution(generator);
   return number;
}

std::string ServerNormal::getType() 
{
   return "norm";
}

ServerConstant::ServerConstant(const std::string& n,double d)
   : Server(n),_dur(d)
{
}   

double ServerConstant::sampleServiceTime() 
{
   std::default_random_engine generator;
   std::uniform_real_distribution<double> distribution(0.0,_dur);
   double number = distribution(generator);
   return number;
   //return _dur;
}


std::string ServerConstant::getType() 
{
   return "const";
}

std::ostream& ServerConstant::print(std::ostream& os)  const
{
   return os << _name <<   "=ServerCst(" << _dur << ','
             << "target=" << _target->getName() << ")";
}

std::ostream& Dispatcher::print(std::ostream& os)  const
{
//   os << _name << "=Dispatch([";
//   for(auto p : _rules) 
//      os << '(' << p.first->getName() << ',' << p.second << ')' << ',';   
//   return os << '\b' << "])";
    return os;
}

Dispatcher::Dispatcher(const std::string& n)
   : Server(n),
     _rd(),
     _gen(_rd()),
     _dis(0.0, 1.0)
{
}

void Dispatcher::addRule(Component* c,double prob)
{
   _rules.push_back(std::pair<Component*,double>(c,prob));
}

std::string ServerExit::getType() 
{
   return "exit";
}

std::string Dispatcher::getType() 
{
   return "disp";
}

double Dispatcher::sampleServiceTime() {
   return _dis(_gen);
}
