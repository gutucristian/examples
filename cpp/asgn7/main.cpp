#include <iostream>
#include <iomanip>
#include "Simulator.hpp"

int main(int argc,char* argv[])
{
   Simulator *s = new Simulator;
   s->read(argv[1]);
   s->run();  
   delete s;
   return 0;
}
