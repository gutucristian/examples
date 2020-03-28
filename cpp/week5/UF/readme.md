## Q4. Sets, efficiently with Union-Find

Implement the Union-Find data structure as an abstraction to represent
sets that can be merged and queried for membership. Union-Find is a
simple data structure where members of the set point to a
representative element (we call him the "center"). Finding out whether
two items 'a' and 'b' belong to the same set boils down to finding the
center for 'a', the center for 'b' and checking whether they are the
same! If the centers are identical, then 'a' and 'b' are in the same
set. This is a data structure that you should have covered in CSE2100
or CSE3500. In doubt, check out wikipedia
<https://en.wikipedia.org/wiki/Disjoint-set_data_structure>. Startup
code is provided. Follow the blueprint below:  

1.  You can follow a similar strategy as before to build this Abstract
Data Type. Namely you will have a UnionFind structure to host the general
high-level methods and a Node structure to refer to the nodes.
2.  Each node  in the data structure will need:
	* a templated value
	* a pointer to the parent node (shared, unique, or weak is your
      decision.... choose wisely!) 
	* optionally, the size of the current tree. 
3.  Your UnionFind container will need an internal list of
pointers to hold onto all the nodes (shared, unique or weak is your
decision, choose wisely!).
4. Union-Find Constructor
	* Simply make sure you initialize your one data member (see above!)
5. Node constructors
	* They should set the size to 1 and hold the value and the pointer
      to a parent node (if there is one as it could be the
      representative of the set!). 
6. A `makeSet` method that creates a singleton set with a single
value. It should: 
		1.  Create an instance of the node struct.
		2.  Add it to the list of nodes in the UnionFind structure.
		3.  Return the shared pointer to the newly created singleton set.
7.  Implement the `setFor` (find) method (again in `UnionFind`). It should:
	* Return a shared pointer to the  representative element for the
	set that the value passed in belongs to.
	* Augment your basic implementation with
      the path compression technique that collapses long path to the
      center to a single hop for every node along the path. 
8.  Implement the merge (union) method (again in `UnionFind`).
	* Find the representatives for both arguments.
	* If those roots are identical, the two elements belong to the
	same set and there is nothing to do.
	* Otherwise, attach the smaller set to the larger set. [*Hint: you
      need to figure out how to efficiently maintain the size of a
      set, i.e., you need to do it in O(1)*] 
9.  Implement the output operator (<<) for the node. It is useful to
    print the sets! Do refer the provided sample output. Here is what
    it should do: 
	* Process each node between the given leaf and the root (center).
	* Display the value of the element and the number of outstanding
      shared pointers. 
	* Display the size of the tree.
