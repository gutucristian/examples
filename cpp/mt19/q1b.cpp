#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

// You must implement your insertionSort here. 
// You must figure out the function protototype
// and its implementation. 
// Do not change the test program.



int main() {
  using namespace std;
  vector<int> uv = {1,30,-4,3,5,-4,1,6,-8,2,-5,64,1,92};
  cout << "init:\t";
  auto nl = insertionSort(uv,[](const int& a,const int& b) { return a < b;});

  for(int v : nl) cout << v << ", ";
  cout << "\b\b"  << endl;

  return 0;
}
