#include <iostream>
#include <vector>

int main()
{
   auto cmp  = [](int a,int b) -> int { 
      if (a == b) return 0;
      else if (a < b) return -1;
      else return 1;
   };
   using namespace std;
   cout << "cmp(1,2) : " << cmp(1,2) << endl;
   return 0;
}
