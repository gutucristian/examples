#ifndef __UF_H
#define __UF_H

#include <iostream>
#include <memory>
#include <list>

template <class T>
struct UnionFind {
   struct Node { 
      // TODO: Add state variables + private methods you might want.
      // TODO: Just the constructors that C++ needs.
      Node(const T& v)  {}  // TODO
      Node(T&& v)       {}  // TODO
      ~Node()           {}  // TODO
   };
   // TODO: This is a list of shared pointers to Node instances defined within the UnionFind<T> struct. 

   // TODO (public API)
   UnionFind() {}  // TODO
   std::shared_ptr<Node> makeSet(const T& v) {} // TODO 
   std::shared_ptr<Node> setFor(std::shared_ptr<Node> v) {} // TODO 
   std::shared_ptr<Node> merge(const std::shared_ptr<Node>& s0,const std::shared_ptr<Node>& s1) {} // TODO
   friend std::ostream& operator<<(std::ostream& os,const std::shared_ptr<Node>& v) {} // TODO
};

#endif
