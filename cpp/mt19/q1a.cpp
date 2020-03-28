#include <list>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <map>

// Write your solution (the mode function) here.
// You need to figure out the function prototype
// and its implementation.
// Do not change the test program!

template<typename Container>
typename Container::value_type mode(Container c) {
	std::map<typename Container::value_type, int> freq;
	for (auto x : c) {
		freq[x] += 1;
	}
	typename Container::value_type res;
	int max = -1;
	for (auto begin = freq.begin(); begin != freq.end(); begin++) {
		if (begin->second > max) {
			max = begin->second;
			res = begin->first;
		}
	}
	return res;
}

int main() {
   using namespace std;
   list<int> a = {1,2,2,3,3,4,2,2,1,8,7,5,3,2,6,3};
   vector<double> b = {1,3.5,3.5,3.5,3,4,2,2,1,8,7,5,3.5,2,6,3.5};
   auto ma = mode(a);
   auto mb = mode(b); 
   cout << "ma = " << ma << endl;
   cout << "mb = " << mb << endl;
}

