#include <vector>
#include <iostream>
#include <math.h>

template <typename T>
bool myfind(std::vector<T>& x,const T& v,std::function<int(T,T)> cmp)
{
   int low = 0,up = x.size()-1;
   while (low <= up) {
      const int mid =(low+up)/2;
      double c = cmp(x[mid],v);
      if (c==0) return true;
      else if (c> 0) up = mid - 1;
      else low = mid + 1;
   }
   return false;
}

int main()
{
   std::vector<double> x = {1,5.0/3.0,5,8,11,25,30,32,47,78,99,101};
   
   bool foundIt = myfind(x,1.66666,
                         std::function<int(double,double)>([](double a,double b) {
                               //[](double a,double b) -> int {
         if (fabs(a-b) < 0.01)
            return 0;
         else if (a > b) return 1;
         else return -1;
                            }));
   
   std::cout << "Found it? " << (foundIt ? "true" : "false") << std::endl;
}
