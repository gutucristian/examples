# Composite Fun

The purpose of this lab is to revisit a problem we evoked once when discussing lambdas.
Namely, how a program like MATLAB or MATHEMATICA is organized in order to manipulate 
expressions as symbolic entitites. Specifically, we are to design and write a collection
of classes that will allow us to:

1. Create expressions that allow us to model multivariate algebraic expressions
2. Create an infrastructure that allows us to evaluate said expressions w.r.t. to specific value 
stores.
3. Create an infrastructure that allows us to compute symbolic partial derivatives.
4. Create an infrastructure that allows us to simplify expressions based on algebraic rules.

## Example

I wish to be able to define an expression such as:

```
f(x,y) = ((x^2 + 2 * x - 1) * sin(3 * y\^2))/(1 + x)
```

Namely, the expression ((x^2 + 2 * x - 1) * sin(3 * y^2))/(1 + x) is bi-variate (variables
are called "x" and "y") and uses the traditional arithmetic operators {+,-,*,/,\^} as well as 
trigonometric functions. 

## Representation

Without a doubt, we should be able to represent this expression as a data-structure in
our programs if we want to manipulate it. The easiest, by far, is to rely on a [Composite 
design pattern](https://en.wikipedia.org/wiki/Composite_pattern). This involves creating a 
hierarchy of classes to support all the types of nodes.

### Leaves

These nodes correspond to the leaves of the expression, namely, constants and variables.

- `Constant`: holds an integer constant.
- `Variable`: holds a string representing the name of the variable.

### Internal

These correspond to the arithmetic operators as well as the intrinsic trigonomic functions. 

- `add`: represents a binary addition (x+y)
- `sub`: represents a binary substraction (x-y)
- `times`: represents a binary multiplication (x*y)
- `div`: represents a binary division (x/y)
- `pow`: represents a binary integral power (x^c)
- `sin`: represents the sine function. (sin(x))
- `cos`: represents the cosine function  (cos(x))
- `tan`: represents the tangent function (tan(x))

### Storage

In order to evaluate the function, we need a way to represent storage. Namely, we want to 
_map_ variable names to values (floating points). Unsurprisingly, this can be done with 
an `std::map` and it suffices to create an abstraction to manipulate the storage. It would be
nice to have a simple API to `get` the value of a variable or `set`  a specific variable to a 
specific value. 


## Operations

### Evaluation

This can be done by having the root of the expression composite, a storage and requesting 
the evaluation of the expression w.r.t. that storage. 

#### Assumptions

- Let's assume that the storage is represented by an object of type `Store`
- Let's further assume that the root of the composite is given by a C++ smart pointer
(e.g.) a `unique_ptr<Expr>` or a `shared_ptr<Expr>` where `Expr` is an abstract expression.

#### Implementation

Write a method with signature

```
double eval(const Store& s);
```

within the composite to be able to evaluate the whole composite w.r.t. `s`.

### Printing

Naturally, we want to be able to print out expressions on the standard output. It 
can be done with a traversal of the composite via a `print` function that dumps in
a C++ stream a textual representation. It is wise to print every node with parentheses 
to avoid any confusion.

#### Implementation

Write a method `print` with signature

```
void print(ostream& os)
```

to be used on the composite. For instance, if the root of the composite is `x`, then the call

```
x->print(cout);
cout << endl;
```
should produce a printout of the expression. 

#### Example

For the expression 

```
x^2 - 3 * x
```

One would expect to see `(x^2) - (3 * x)` as a print out of the composite. 

### Derivation

This can be done by having the root of the expression composite, the name of the variable
with respect to which we wish to compute the derivative and apply the rules from calculus
to compute a partial. 

#### Implementation

Write a method with signature

```
shared_ptr<Expr> derive(std::string name);
```

which computes the derivative of the receiver object w.r.t. the variable named `name`. 
The output is the root of a composite.\

#### Example

Computing the derivative of 

```
x^2 + 2 * y - 3 * x + 1
```

with respect to `x` is:

```
2 * x - 3
```

Note that if you ignore algebraic identities, you may produce something like:

```
(2 * x * 1) + (0 * y + 2 * 0) - (0 * x + 3 * 1) + 0
```

which, strictly speaking is equivalent to the above and follows directly from applying
the chaining rule during derivation.


## Closing remarks

In a perfect world, we would be, like Mathematica, reading the expression from the standard input. 
While valuable, this is a bit beyond the point of the exercise. For the sake of focusing on creating
the lab, assume that we are "hard-coding" the expressions in our main program (in c++). For instance,
to create the expression

```
x * y + 1
```

One would write a program like:

```
using namespace std;
int main() {
	auto x = make_shared<Variable>("x");
	auto y = make_shared<Variable>("y");
	auto root = make_shared<Add>(make_shared<Mul>(x,y),make_shared<Constant>(1));
	root->print(cout);
	cout << endl;
}
```

Note that with the definition of a few operators, the main program could be very readable. For
instance, one could write:

```
auto operator+(shared_ptr<Expr> e1,shared_ptr<Expr> e2) {
	return make_shared<Add>(e1,e2);
}
auto operator+(shared_ptr<Expr> e1,int e2) {
	return make_shared<Add>(e1,make_shared<Constant>(e2));
}
auto operator*(shared_ptr<Expr> e1,shared_ptr<Expr> e2) {
	return make_shared<Mul>(e1,e2);
}
```

the test program would become:

```
using namespace std;
int main() {
	auto x = make_shared<Variable>("x");
	auto y = make_shared<Variable>("y");
	auto root = x * y + 1;
	root->print(cout);
	cout << endl;
}
```



