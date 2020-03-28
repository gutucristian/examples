#ifndef __SERVER_H
#define __SERVER_H

#include <random>
#include "component.hpp"
#include <vector>

class Server: public Component {
protected:
   Component*           _target;
   //Buffer*                _feed;
   void addTarget(Component* c2) { _target = c2;}
public:
   double busyUntil;
   std::vector<double> processingTimes;
   Buffer*                _feed;
   Server(const std::string& n);
   virtual ~Server() {}
   virtual std::string getType() {}
   virtual double sampleServiceTime() = 0;
   void setFeed(Buffer* b) { _feed = b;}
   Component* getTarget()  { return _target;}  
};

class ServerExponential :public Server {
   std::random_device _rd;
   std::mt19937 _gen;
   std::exponential_distribution<> _dis;
   std::string type;
   double _rate;
   std::ostream& print(std::ostream& os)  const;
public:
   ServerExponential(const std::string& n,double r);
   std::string getType();
   double sampleServiceTime();
};

class ServerNormal :public Server {
   double _mean,_deviation;
   std::ostream& print(std::ostream& os)  const;
public:
   ServerNormal(const std::string& n,double m,double d);
   double sampleServiceTime();
   std::string getType();
};

class ServerConstant :public Server {
   double _dur;
   std::ostream& print(std::ostream& os)  const;
public:
   ServerConstant(const std::string& n,double d);
   double sampleServiceTime();
   std::string getType();
};

class ServerExit :public Server {
   std::ostream& print(std::ostream& os)  const { return os;}
public:
   ServerExit(const std::string& n) : Server(n) {
      _feed = nullptr;
   }
   double sampleServiceTime() { return 0;}   
   std::string getType();
};

class Dispatcher :public Server {
   std::random_device _rd;
   std::mt19937 _gen;
   std::uniform_real_distribution<> _dis;
   std::string type;
   //std::vector<std::pair<Component*,double> > _rules;
   std::ostream& print(std::ostream& os)  const;
public:
   std::vector<std::pair<Component*,double> > _rules;
   Dispatcher(const std::string& n);
   ~Dispatcher() {}
   void addRule(Component* c,double prob); 
   double sampleServiceTime();    
   std::string getType();
};

#endif
