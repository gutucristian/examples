#include <vector>
#include <iostream>
#include <math.h>

template <class T>
bool find(std::vector<T>& x,const std::function<int(double)>& cmp)
{
  int low = 0,up = x.size()-1;
  while (low <= up) {
    const int mid = (low + up)/2;
    double c = cmp(x[mid]);
    if (c==0)
      return true;
    else if (c > 0)
      up = mid-1;
    else
      low = mid+1;    
  }
  return false;
}


auto mybind(const std::function<int(double,double)>& f,double b) {
   return [f,b](double a) {
      return f(a,b);
   };
}

int main()
{
   using namespace std::placeholders;
   std::vector<double> x = {1,5.0/3.0,5,8,11,25,30,32,47,78,99,101};
   const double eps = 0.01;
   auto cmp = [eps](double a,double b) -> int {
      if (fabs(a-b) < eps)
         return 0;
      else if (a > b)
         return 1;
      else return -1;         
   };
   bool foundIt = find(x,mybind(cmp,1.666666666));
   std::cout << "Found it? " << (foundIt ? "true" : "false") << std::endl;
}
