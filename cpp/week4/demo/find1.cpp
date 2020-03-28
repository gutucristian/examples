#include <iostream>
#include <vector>

template<class T> 
bool find(const std::vector<T>& x,const T& v) {
   int low = 0, up = x.size()-1;
   while(low <= up) {
      int mid = (low + up)/2;
      if (v == x[mid]) return true;
      else if (v < x[mid]) up = mid - 1;
      else low = mid + 1;
   }
   return false;
}

int main()
{
  std::vector<int> x = {1,5,8,11,25,30,32,47,78,99,101};
  bool foundIt = find(x,101);
  std::cout << "Found it? " << (foundIt ? "true" : "false") << std::endl;
}
