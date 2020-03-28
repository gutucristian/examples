#ifndef __LIST_H
#define __LIST_H
#include <memory>
#include <iostream>

template <class T>
class List {
public:
   class Node {
      friend class List<T>;
      // TODO (remember that you may have to add quite a few methods!
   };
private:
   // TODO
public:
   void insert(const T& v) {} // TODO
   void append(const T& v) {} // TODO
   void forEach(std::function<void(const T&)> body) {} // TODO
   // TODO
   // Remember that you may have to add methods to meet all the requirements. 
};

#endif
