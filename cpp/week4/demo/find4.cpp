#include <vector>
#include <iostream>
#include <math.h>

int compare(double a,double b)
{
   if (fabs(a-b) < 0.01)
      return 0;
   else if (a > b)
      return 1;
   else return -1;
}

template <class T>
bool find(std::vector<T>& x,const T& v)
{
  int low = 0,up = x.size()-1;
  while (low <= up) {
    const int mid = (low + up)/2;
    int c = compare(x[mid],v);
    if (c==0)
      return true;
    else if (c > 0)
      up = mid-1;
    else
      low = mid+1;    
  }
  return false;
}

int main()
{
   std::vector<double> x = {1,5.0/3.0,5,8,11,25,30,32,47,78,99,101};
   //bool foundIt = find(x,1.666666666);
   bool foundIt = find(x,32.0);
   std::cout << "Found it? " << (foundIt ? "true" : "false") << std::endl;
}
