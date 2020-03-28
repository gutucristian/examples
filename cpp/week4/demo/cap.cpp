#include <iostream>
auto makeAFoo(int& x) {
   auto foo = [x](int y) -> int {
      return y + x++;
   };
   return foo;
}
int main() {
   int a=42,b=4200;
   auto foo1 = makeAFoo(a);
   auto foo2 = makeAFoo(b);
   std::cout << foo1(10) << std::endl;
   std::cout << foo1(10) << std::endl;
   std::cout << "a = " << a << std::endl;
   std::cout << foo2(10) << std::endl;
   return 0;
}
