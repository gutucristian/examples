#include <iostream>
#include <string>
using namespace std;
int sumOf(const string& a) {
   int ttl=0;
   for(int i=0;i< a.size();i++)
      ttl += a[i];
   return ttl;
}
int main() {
   string x = { 'H','e','l','l','o'};
   int s = sumOf(x);
   cout << "s= " << s << endl;
   cout << "x= " << x << endl;
   return 0;
}
