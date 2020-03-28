#include <iostream>
#include <stack>

int main()
{
   using namespace std;
   stack<double> si;
   for(int i=0;i<5;i++) si.push(((double)i)/(i+1));
   while(!si.empty()) {
      cout << "value:" << si.top() << endl;
      si.pop();
   }
   return 0;
}
