# To C++ and beyond!

This assignment, while long to read, does not require a lot of
code. In addition, we do provide the skeleton for several key
pieces. Make sure you fully understand the skeleton and this handout
before starting. In particular, we do provide the test code each time
which you should use "as is" (no modifications!). Your job is to build
the data structures and meet the APIs requirements to make the test
code run "unmolested".

Good luck!

## Q1. A Raw List

Your task is to implement a singly linked-list with data items of some
templated type ```T```. The list should be flexible enough to let you
use it for *any* type ```T```. In particular, it should work for
```int``` as well as something as cute as  
```shared_ptr<Foo>``` where ```Foo``` is a user-defined class or
struct. The list below gives you a blue print of the steps to follow.  

1.  Create a templated list class.
	* Introduce a List class to hold onto the head of the list (note
      there is no tail!). 
	* Introduce a Node class to represent list nodes (pairs of data
      and pointer).  
	* Embed a templated attribute for the data in the node 
	* Embed a raw (C) pointer to link a node to its successor in the list
2.  Build Constructors.
	* Introduce a default constructor for the list
	* Introduce a constructor for the node that takes a datum of type
	```T``` and the pointer to a tail (the address of a node!).  
3. Introduce two methods to modify the list
	* Add a method ```void insert(const T& value)``` that adds the
      value in front of the list. 
	* Add a method ```void append(const T& value)``` that adds the
      value at the end of the list. Since the list has no tail, this
      routine runs on O(n) where n is the length of the list.  
4.  Build a "scanning" function to loop over the content of the list
      and call a lambda on each element. Namely the function you write
      should be:  

        void forEach(std::function<void(const T&)> body)

5.  Extend your implementation (namely add methods whenever
    appropriate) so that the code function correctly when the template
    is instantiated with a ```unique_ptr<T>```. Namely, the following
    test should work just fine! 

        List<unique_ptr<int>> aList;
        aList.insert(make_unique<int>(42));
        aList.append(make_unique<int>(-42));
   the code should result in producing the list (42,-42). To succeed,
      you need to add methods that accept rvalue references (namely,
      arguments such as ```(T&& t)```) and rely on move semantics
      (```std::move```) within constructors and assignment
      operators. This will affect  
	* Node constructor(s)
	* insert method(s)
	* append method(s)
	
Do refer to the provided test program. It should run **unmodified**.


## Q2. Let's make it unique!

Redo steps 1-5 of question 1 but this time make sure that you use
unique_ptr for the pointers to the next element (for chaining
the list nodes) and that you can still instantiate the singly-linked
list with a data type that is a ```unique_ptr<T>``` or a
```shared_ptr<T>``` for any type ```T```.
	
## Q3. There is nothing like sharing!
	
Extend your previous solution  with shared pointers. The objective is
to be able to have, at any point in time, more than one 'owner' for a
given list node. That is necessary, for instance, as soon as you add a
tail pointer in the list (that points to the tail, in which case, both
the tail pointer and the second to last node of the list point to the
last node of the list!). This is also useful if you wish to return a
shared pointer to a node to act as a "Locator" design pattern. (a
Locator is an object used to "find" an item into a container without
revealing anything about the container implementation. Typically, it
would be an object with no public methods that must be passed to a
method of the container to act on the entry it helps locate). To do
your work, we provide the following blueprint (in the ```q3```
folder).  

1.  Change your next pointers to shared pointers within the list
nodes. Make sure that no methods of the Node class are public. Even
better, embed the Node class within the List class (it should be a
public nested class with only public constructors).  
2.  Upgrade the list class.
	* Use a shared pointer to reference the head of the list.
	* Use a shared pointer to reference the tail of the list.
	* Move your insert and append functions to be elements of the wrapper class.
3.  Adapt the insert and append methods to take advantage of the new
structure. Specifically, change their signatures to return the
```Node``` locator as an opaque object (with no visible methods). The
four methods should be

        std::shared_ptr<Node> insert(const T& v) ...
        std::shared_ptr<Node> append(const T& v) ...
        std::shared_ptr<Node> insert(T&& v) ...
        std::shared_ptr<Node> append(T&& v) ...

4.  Add a change method to modify the data value of an item given a
locator. Namely, the method would be 

        void  change(std::shared_ptr<Node>& loc,const T& v) ...
        
and it would be called with the shared pointer to a Node that
```insert``` or ```append``` manufactured.  

5.  Add a nested iterator class for your List.
	* An iterator should point at a single element in the list, not the data.
	* Implement the *, ++, == and != operators for your iterators.
	* Add begin and end methods to your List class. They should return
      instances of iterators pointing to the beginning and just past
      the end. With these methods and iterators, we are able to
      *ditch* the forEach method of Q1,Q2 and use the standard range
      loops of C++! 
6.  Your List should now work with the STL algorithms such as for_each
    as well as range loops. Do test! 
	
