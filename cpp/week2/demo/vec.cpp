#include <iostream>
#include <vector>
using namespace std;

template <class T>
T sum(vector<T>& vec) {
   T ttl;
   for(T v : vec) ttl = ttl + v;
   return ttl;
}


int main() {
  vector<double> vec;
  for(int i=0;i<10;i++)  {
     double v = i;
     vec.push_back(v/(v+1));
  }

  for(double v : vec) 
    cout << v << " ";
  cout << endl;
  cout << "sum:" << sum(vec) << endl;

  vector<string> vs;
  vs.push_back(string("Hello "));
  vs.push_back(string("cruel "));
  vs.push_back(string("world "));

  cout << "sentence:" << sum(vs) << endl;
  return 0;
}
