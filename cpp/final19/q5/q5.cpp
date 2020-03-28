#include <iostream>
#include <memory>
#include <list>

/** Forward declaration of the handle class defined below */
template <class T> class fvec;

// Abstract class for vectors 
template<class T> class fvec_base:public std::enable_shared_from_this<fvec_base<T>> {
public:
   typedef std::shared_ptr<fvec_base<T>> Ptr;
   fvec_base() {}
   virtual ~fvec_base() {}
   virtual Ptr copy() = 0;
   virtual T at(int idx) const = 0;
   virtual Ptr write(int idx,const T&v) = 0;
   virtual int size() const = 0;
};

// Tombstone to refer to vectors
template <class T> class Tombstone {
   typename fvec_base<T>::Ptr _ptr;
public:
   typedef std::shared_ptr<Tombstone<T>> Ptr;
   Tombstone(typename fvec_base<T>::Ptr p) : _ptr(p) {}
   // TODO: Implement the pure methods of the abstract class plus anything
   //       you might need. 

   // Printing of the tombstone is provided!
   friend std::ostream& operator<<(std::ostream& os,const Tombstone& t) {
      return os << &t << ':' << t._ptr.get();
   }
};

// Handle to manage access to vector entries
template <class T> class fvec_entry {
   friend class fvec<T>;
   typename Tombstone<T>::Ptr _stone;
   int                        _index;
   fvec_entry(typename Tombstone<T>::Ptr c,int i) : _stone(c),_index(i) {}
public:
   operator T() const                   {
      // TODO: This is the operator to _read_ from an entry
   }
   fvec_entry<T>& operator=(const T& e) {
      // TODO: This is the operator to _write_ to an entry
   }
};

// Concrete vector with actual storage
template <class T> class fvec_real :public fvec_base<T> {
   int    _msz;
   T* _storage;
public:
   // TODO Implement everything you might need for the actual vector
};

// cow vector that refers to the original
template <class T> class fvec_cow : public fvec_base<T> {
   typename Tombstone<T>::Ptr _orig;
public:
   // TODO Implement everything you might need for the copy-on-write vector
};

// user-level vector abstraction
template <class T> class fvec {
   typename Tombstone<T>::Ptr _stone;
public:
   fvec(int sz) {
      // TODO
   }
   fvec(const fvec<T>& other) {
      // TODO
   }
   fvec<T>& operator=(const fvec<T>& other) {
      // TODO
   }
   void reset() {
      // TODO
   }
   fvec_entry<T> operator[](int idx)   {
      // TODO
   }
   T  operator[](int idx) const        {
      // TODO
   }
   int size() const                    {
      // TODO
   }
   // The printing routine is graciously provided!
   friend std::ostream& operator<<(std::ostream& os,const fvec<T>& v) {
      if (v._stone == nullptr)
         return os << "[]";
      else {
         os << '[' << *v._stone << ' ';
         for(int i=0;i < v.size();i++) 
            os << v[i] << ' ';         
         return os << ']';
      }
   }
};

void test1() {
   /**
    * Test that the large vector v0 is not actually copied at first. 
    * Instead v1 is a copy on write version that only physically copies
    * v0 when it is written to with the [] operator/assignment.
    * If you wish to verify with valgrind, I suggest making v0's size 1000
    * (to test faster!). The size is large to make the pause noticeable when
    * copies do occur. 
    */
   using namespace std;
   fvec<int> v0(100000000);         // That takes O(n) to initialize
   for(int i = 0;i < 2;i++) {
      fvec<int> v1(v0);             // this should run in O(1)
      for(int j=0;j < 10;j++)
         cout << v1[j] << endl;     // those should be fast 10 x O(1)
      v1[1+i] = -i-1;               // actual write causing the copy O(n)
      v1[2+i] = -i-2;               // write is fast --O(1)-- now that the cow is done
      for(int j=0;j < 10;j++)
         cout << v1[j] << endl;     // those should be fast 10 x O(1)
   }   
}

void test2() {
   /**
    * Test that checks that even if v0 is reset, the lazy copy in v1 is still
    * usable and can do both reads and writes. 
    */
   using namespace std;
   fvec<int> v0(100);
   {
      fvec<int> v1(v0);

      cout << "v0=" << v0 << endl;
      cout << "v1=" << v1 << endl;

      v0.reset();
      v1[0] = -1;
      v1[1] = -2;

      cout << "v0=" << v0 << endl;
      cout << "v1=" << v1 << endl;
   }
}

void test3() {
   /**
    * Test that verifies that, upon a copy-on-write, even if there is a chain
    * of references v3->v2->v1->v0, v0 is copied only once. Here, the code writes
    * to v3 and therefore v0 is lazily copied there, with no effect on v1/v2. 
    * Note: The printout of fvec shows two addresses: that of the tombstone and that
    *       of the actual vector. 
    */
   using namespace std;
   fvec<int> v0(10);
   fvec<int> v1(v0);
   fvec<int> v2(v1);
   fvec<int> v3(v2);

   cout << "v0=" << v0 << endl;
   cout << "v1=" << v1 << endl;
   cout << "v2=" << v2 << endl;
   cout << "v3=" << v3 << endl;

   v3[0] = -1;
   
   cout << "v0=" << v0 << endl;
   cout << "v1=" << v1 << endl;
   cout << "v2=" << v2 << endl;
   cout << "v3=" << v3 << endl;

}


int main()
{
   test1();
   test2();
   test3();
   return 0;
}

