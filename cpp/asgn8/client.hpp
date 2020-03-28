#ifndef __CLIENT_H
#define __CLIENT_H

#include <string>

#include "component.hpp"

class Client {
  public:
    int id;
    double t0;
    double t1;
    Component *target;
    Client(Component *target, double t0, int id): target(target), t0(t0), id(id) {
      //std::cout << "Create Client (id=" << id << ") at " << t0 << std::endl;
    };
};

#endif

