#include <iostream>
#include <iomanip>
#include "Simulator.hpp"

int main(int argc,char* argv[])
{
   Simulator *s = new Simulator;
   s->read(argv[1]);
   s->run(atof(argv[2]));  
   return 0;
}
