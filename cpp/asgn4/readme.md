# Functional Programming in C++
		
## Question 1: Functional operations.

The `forEach` function should apply a function to each of the elements
between the two iterators.  Once working, this will allow you to use
the << operator to print out the elements in your lists.

The `reduce` (or fold left) function should iterate over the elements
between the two iterators applying the binary operation to a base
value and the current element in the container.  Once it has read all
of the elements in the container, it should return the result of the
last binary operation.

The `foldr` (fold right) works the opposite direction, by recursively
peeling off the left most elements of the container and then applying
the binary operation to the current element and the result of the
recursion.

Finally, the `filter` function comes in two parts.  The basic form
takes a container and a predicate as its parameters.  It uses those to
call the advanced form that uses two input iterators and an output
iterator.  The filter function adds an element to the output container
if the result of applying the predicate function to the element is
true.  You will need to use the C++ back_inserter function to create
the output iterator.  The back_inserter function creates an iterator
at the end of a container, where you can add new elements.  An example
is shown in q1.cpp's main function.

## Question 2. Sieves

This question asks you to implement a variant of the Sieve of
Eratosthenes based around filtering by modulus.  To do this, you will
need to build infinite lists that you can filter based on a given
value.  The "from" function should create a new infinite list with a
given starting point and a function to compute the next element in the
list.  Applying a filter to such a list should produce another
infinite list.  After that the "sift" function should apply a filter
to an infinite list that excludes any elements whose modulus
w.r.t. the second parameter is zero.  Finally, the actual sieve
function creates an infinite list by sifting an infinite list to
remove multiples of the first element in the list, leaving another
infinite list whose first element will be another prime number.

## Question 3. Taylor expansions.

This is perhaps the easiest.  For this problem, you should write a
function that returns a function that can calculate the results of the
Taylor series expansion for sine to the specified number of terms.
