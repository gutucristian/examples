#include <iostream>
#include <vector>
#include <math.h>

int main()
{
   double epsilon = 0.01;
   auto cmp  = [&epsilon](double a,double b) -> int { 
      if (fabs(a-b) <= epsilon) return 0;
      else if (a < b) return -1;
      else return 1;
   };
   using namespace std;
   cout << "cmp(1,1.00001) : " << cmp(1,1.00001) << endl;
   epsilon = 0.0000001;
   cout << "cmp(1,1.00001) : " << cmp(1,1.00001) << endl;   
   return 0;
}
