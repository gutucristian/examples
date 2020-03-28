#include <iostream>
#include <iomanip>
#include "model.hpp"
#include "action.hpp"

int main()
{
   using namespace std;

   auto m = SVG::createModel("silly");
   auto g = make_shared<SVG::Group>();
   m->add(g);
   g->add(make_shared<SVG::Rect>(10,10,100,100));
   g->add(make_shared<SVG::Line>(10,10,110,110));
   g->add(make_shared<SVG::Line>(10,110,110,10));
   m->add(make_shared<SVG::Circle>(50,50,40));
   	
   cout << m << endl;

   auto m2 = translate(m,20,20);  
   cout << m2 << endl;
   auto m3 = scale(m2,2);   
   cout << m3 << endl;
   move(g,-100,-100);
   cout << m << endl;

   return 0;
}
