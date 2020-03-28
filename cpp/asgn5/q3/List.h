#ifndef __LIST_H
#define __LIST_H
#include <memory>
#include <iostream>

/*
 * The list class encapsulates a pair of pointers to the head 
 * and the tail of the list. It means that the tail has at least 
 * 2 pointers going to it and unique_ptr is thus not suitable. We need
 * to use shared_ptr instead (a singly linked list with ONLY a head ptr 
 * would alleviate the issue.
 *
 * The code below also uses a "locator" design pattern in the form of 
 * returning a reference to the List<T>::Node as an opaque type (all the 
 * useful methods are private, so is the state). While this is useful, it
 * again implies that we can have > 1 reference to list nodes and again mandates
 * shared_ptr (giving up on the locator pattern would avoid the issue). 
 *
 * Using a List object and a separate Node object is good to hide / encapsulate
 * the state of the list. Nothing about the node or the list transpires from 
 * the API of the list.
 * - The data (T) is embedded directly in the list Node. (no pointer there)
 * - The Node class is nested in the List class (to clean up the global name space)
 * - The implementation provides an iterator with the required methods to increment
 *   the iterator and access the element it refers to. 
 * - Using shared_ptr for the list nodes is _good_ as we avoid writing a destructor and
 *   still get  correct recursive deallocation when the list goes away.
 * - There is no need for weak_ptr since nothing is circular.
 * - The begin/end methods simply manufacture an iterator for the list.
 * - Conformance with the STL APIs (having iterators) allow us to reuse all the STL
 *   algorithms (e.g., for_each) as well as the range loops. 
 * - The Node class needs custom constructors with lvalue reference and rvalue reference
 *   to correctly handle a list of unique_ptr which would require move semantics.
 */

template <class T>
class List {
public:
   class Node {
      T val;
			std::shared_ptr<Node> next = NULL;
			Node() {

			}
   };
	 std::shared_ptr<Node> _head = NULL;
	 std::shared_ptr<Node> _tail = NULL;
private:
   // TODO
 public:
   class iterator {
      friend class List<T>;
      friend class List<T>::Node;
      //TODO
   public:
      //TODO
      iterator(const iterator& o) {} // TODO
      const T& operator*()        {} // TODO (dereference operator, returns the current element)
      const iterator& operator++() {} // TODO (pre-increment operator. used for expressions such as ++i 
      iterator operator++(int)     {} // TODO (post-increment operator, used for expressions such as i++
      bool operator==(const iterator& i2){} // TODO (equality operator. True if the receiver and i2 point to the same location)
      bool operator!=(const iterator& i2){} // TODO (disequality operator. Negation of equality ;-)). 
   };
   // TODO
   List() {}  // TODO
   ~List() {} // TODO
   std::shared_ptr<Node> insert(const T& v) {
	 		
	 } // TODO
   std::shared_ptr<Node> insert(T&& v)      {} // TODO (move semantics!)
   std::shared_ptr<Node> append(const T& v) {} // TODO
   std::shared_ptr<Node> append(T&& v)      {} // TODO (move semantics!)
   void  change(std::shared_ptr<Node>& loc,const T& v) {} // TODO
   iterator begin() const { return iterator(_head);}         // graciously provided ;-) [clearly, you'll need a _head]
   iterator end()  const  { return iterator(_tail->_next);}  // graciously provided ;-) [clearly, you'll need a _tail]
};

#endif
