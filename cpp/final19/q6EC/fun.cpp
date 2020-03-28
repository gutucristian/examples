#include <type_traits>
#include <stdio.h>

template <class T,T x> struct Square {
   static const T value = x * x;
};

template <class T,T x> struct Opposite {
   static const T value = - x;
};

template <int ...Vs> struct IVector {
  using Type = IVector<Vs...>;
};

// TODO: Implement the IMap meta-programming construction



// Test code. Do not modify below for the handin
using V0 = IVector<1,2,3>;
static_assert(std::is_same<IVector<1,4,9>::Type   ,IMap<Square,int,V0>::Type>::value,"not ok map1");
static_assert(std::is_same<IVector<-1,-2,-3>::Type,IMap<Opposite,int,V0>::Type>::value,"not ok map2");

