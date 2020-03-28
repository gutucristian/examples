#include <iostream>

template <typename T> struct UPtr {
   T*  _ptr;
   UPtr() { _ptr = nullptr;}
   UPtr(T* p) { _ptr = p;}

   UPtr<T>& assign(UPtr<T>&&  p) {
      if (_ptr)
         delete _ptr;
      _ptr = p._ptr;     // transfer ownership
      p._ptr = nullptr;  // relinquish ownership
      //const_cast<UPtr<T>&>(p)._ptr = nullptr;
      return *this;
   }
};
template <class T>
void foo(const UPtr<T>& p) {
   std::cout << "Foo p = " << p._ptr << "\t value=" << *p._ptr << std::endl;
}
template <class T> UPtr<T> makeFoo(T v) {
   T* p = new T;
   *p = v;
   return UPtr<T>(p);
}

int main() {
   using namespace std;   
   UPtr<int> x(new int);
   UPtr<int> y;
   cout << "x = " << x._ptr << endl;
   cout << "y = " << y._ptr << endl;
   y.assign(std::move(x));
   cout << "x = " << x._ptr << endl;
   cout << "y = " << y._ptr << endl;
   foo(y);

   UPtr<int> w;
   //makeFoo(42);
   w.assign(makeFoo(42));
   
   cout << "w = " << w._ptr << "\t value=" << *w._ptr << endl;
   
   return 0;
}
