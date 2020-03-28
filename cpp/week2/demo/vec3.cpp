#include <iostream>
#include <vector>
using namespace std;

template <class Container>
void rprint(Container& c) {
   for(auto k = c.rbegin();k != c.rend();k++) {
      cout << *k << " ";
   }
   cout << endl;
}

int main() {
  vector<int> vec;
  for(int i=0;i<10;i++) 
    vec.push_back(i);
  for(int i=0;i < vec.size();i++) {
     cout << vec[i] << " ";
  }
  cout << endl;
  
  for(vector<int>::iterator k = vec.begin();k != vec.end();k++) {
     cout << *k << " ";    
  }
  cout << endl << "Reverse!" << endl;;
  for(auto k = vec.rbegin();k != vec.rend();k++) {
     cout << *k << " ";    
  }
  cout << endl;

  rprint(vec);
  
  vector<int>::iterator on3 = vec.begin() + 2;
  cout << "rank(3) is: " << *on3 << endl;
  *on3 = 17;
  cout << "rank(3) is: " << *on3 << endl;
  return 0;
}
