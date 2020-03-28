#include <iostream>

int fact(int n) {
   if (n==0)
      return 1;
   else {
      int rc = fact(n-1);
      if (rc < 0) throw std::string("Overflow");
      return rc * n;
   }
}

int main()
{
   try {
      int x = fact(20);
      std::cout << "Result is: " << x << std::endl;
      return 0;
   } catch(std::string s) {
      std::cout << "Something went wrong! " << s << std::endl;
      return 1;
   }
}
