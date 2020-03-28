#include <iostream>

using namespace std;
int main()
{
   std::cout << "int      :" << sizeof(int) << endl;
   std::cout << "long     :" << sizeof(long) << endl;
   std::cout << "long long:" << sizeof(long long) << endl;

   std::cout << "long dbl :" << sizeof(long double) << endl;
   return 0;
}
