#include <iostream>
#include <list>
#include <functional>
#include <vector>
#include <bits/stdc++.h> 

/**
 * This is a convenience function that prints out a list on an output stream
 */

template <class T>
std::ostream& operator<<(std::ostream& os,const std::list<T>& c) {
   for(auto v : c)
      os << v << " ";
   return os;
}

/**
 * Infinite Streams in C++
 * This is the _representation_ of an infinite stream in C++
 * At is core, it is merely a structure with two attributes
 * - a root value 
 * - a closure (function) to generate the tail of the stream. 
 * For instance, the stream of natural numbers starting at 2 has:
 * - a root value = 2
 * - a closure that produces another infinite stream whose root is 3 and whose generator is 
 *   a function that produces the next infinite stream. 
 * The trick to create the stream of natural numbers is to rely on a function that computes the next number
 * and use that within a closure that implements a stream generator.
 * In ML, this would be something like:
 * fun from root next = pair(root,fn () => from (next root) next)
 * namely, the from function that a root and a "next" function and creates a pair with the root and an
 * anonymous function that returns --when called-- a stream rooted at the value after root.
 * In ML, the stream of naturals can then be obtained with:
 * val nat = from 2 (fn x=> x+ 1)
 */

template <typename T>
struct Stream {
   T                       root;
   std::function<Stream<T>()> g;
   Stream(T r,std::function<Stream<T>()> f) { root = r; g = f; }
};

/**
 * You will typically need a few "helper" functions (besides from) to manipulate infinite streams.
 * In particular, you will need:
 * 1. a head function that returns the root of a stream
 * 2. a tail function that returns the tail (i.e., a stream rooted at the next value of the current stream)
 * 3. a take function which, given a stream s and a value k, produces a normal list with the first k values from s
 * 4. a higher-order filter function which, given a stream s and a predicate p, returns a new stream extracted from s
      that only contains the elements satisfying predicate p,

 * Armed with those, you are in a position to write the sieve algorithm that simply sifts through the
 * stream it produces to eliminate numbers that are multiple of the prime seen at the head of the stream. In
 * ML this can be done quite simply with:

 * fun sieve s = let val h = head s
                     val t = tail s
                 in pair(h,fn () => sieve (filter t (fn x => x % h != 0)))
                 end
 *
 * Namely, sieve gets the head (h) and the tail (t) of the stream (s) and returns a stream (pair) starting with h
   -- h is a prime --, and a generator that applies the sieve to the sifted stream to eliminate the multiples of the head.
   See the main program below that provides example calls to:
   1. Creates the stream of nats
   2. filters the stream of nats to only retain the even numbers
   3. uses take to pick up the first 20 naturals (from 2)
   4. demonstrates the sifting with 2
   5. and finally, picks up the first 100 primes. 
 */

template<class S, class T>
std::list<T> take(S s, T k) {
	std::list<T> res;
	while (k > 0) {
		res.push_back(s.root);
		s = s.g();
		k--;
	}
	return res;
}

template<class T, class Transform>
T filter(T t, Transform f) {
	while (f(t.root) == false)
		t.root++;
	t.g = [=]() -> T {
		T tmp = t;
		tmp.root++;
		return filter(tmp, f);
	};
	return t;
}

template<typename T, typename Transform>
Stream<T> from(T t, Transform f) {
	struct Stream<T> res{t, [=]() -> Stream<T> {
		return from(f(t), f);
	}};
	return res;
}

template<class T, class U>
T sift(T t, U u) {
	return filter(t, [=](int v) { return v % u != 0; });
}

//template<class T>
void sieve(int n) {
	bool prime[n+1];
	std::memset(prime, true, sizeof(prime));
	
	for (int p=2; p*p<=n; p++) {
		if (prime[p] == true) {
			for (int i=p*p; i<=n; i+=p)
				prime[i]=false;
		}
	}

	//t.g = [=]() -> T {
	//	return sieve(sift(t, t.root));
	//};
	
	for (int p=2; p<=n; p++)
		if(prime[p])
			std::cout << p << " ";

	//return t;
	std::cout << std::endl;
}

int main()
{
   using namespace std;
   auto nat = from(2,[](int n) { return n+1;});
   auto even = filter(nat,[](int v) { return v % 2 == 0;});
   cout << take(nat,20) << endl;
   cout << take(even,20) << endl;
   cout << take(sift(nat,2),20) << endl;
   //cout << "primes:" << take(sieve(nat),100) << endl;
   sieve(541);
   return 0;
}
