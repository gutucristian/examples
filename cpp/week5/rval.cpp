#include <iostream>
#include <functional>

template <typename T>
struct UPtr {
   T* _ptr;
   UPtr(void) { _ptr = nullptr;}
   UPtr(T* p) { _ptr = p;}

   UPtr<T>& assign(const UPtr<T>& p) {
      std::cout << "assign(" << this << "," << &p << ")" << std::endl;
      if (_ptr)
         delete _ptr;
      _ptr = p._ptr;
      //p._ptr = nullptr;
      return *this;
   }
};

UPtr<int> makeInt() {
   return UPtr<int>(new int);
}

int main()
{
   using namespace std;
   
   UPtr<int> p(new int);

   UPtr<int> w;

   w.assign(p);
   //w.assign(std::move(p));
   

   UPtr<int> q;
   q.assign(makeInt());

   cout << "P=" << p._ptr << endl;
   cout << "W=" << w._ptr << endl;
   cout << "Q=" << q._ptr << endl;

   return 0;  
}
