# Objective

Create two programs that implement a polynomial ADT (Like in CSE3100).

- The first program should use pointers, and const as needed and use 
  a C++ style. Feel free to use the STL if need be. The modus operandi
  is KISS: Keep It Simple and Stupid. 

- The second program should use _references_, const and exceptions
  whenever needed to bring it even closer to a C++ way. Feel free to
  use the STL if need be.
  
# ADT Expectations

1. Polynomials are univariate
2. Polynomials can have an arbitrary degree
3. Polynomials are sums of monomials of the form c_k * x^k where c_k
   is a constant and k is the degree of the monomial.
4. You should be able to print a polynomial
5. You should be able to add a monomial to a polynomial (in place modification)
6. You should be able to add two polynomials (and get a new one as a
   result)
7. You should be able to evaluate a polynomial at a point (value for
   its variable). 
8. You should be able to read a polynomial from the standard
   input. Format should be


   `
   nbMono c0 k0  c1 k1 ....  cn kn
   `


     where nbMono is the number of monomials and each monomial is given
   by a pair `ci ki` in which `ci` is the coefficient (float) and `ki`
   is the exponent of the i^th term (an integer). 
   
# Goals

Your objective is to write as little code as possible and write code
that is elegant, highly readable, and easy to maintain. You can (if
you wish, but it is not necessary) use `struct` like in C. But do not
attempt to make objects. Stick to functions for now. 

# What to pay attention to

- Memory management
- const usage
- reference usage
- error handling

Good luck!



