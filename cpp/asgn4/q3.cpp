#include <iostream>
#include <iomanip>
#include <math.h>
#include <functional>

/*
 *  * Your task is to implement makeSineToOrder(k)
 *   * This is templated by the type of values used in the calculation.
 *    * It must yield a function that takes a value of the specified type and
 *     * returns the sine of that value (in the specified type again)
 *      */

long double radians(long double degrees) {
	long double radians;
	long double pi = 3.14159265358979323846264338327950288419716939937510L;
	radians = (pi/180)*degrees;
	return radians;
}

unsigned long long int factorial(int n) {
	unsigned long long int fact = 1;
	for(; n >= 1; n--)
		fact = fact * n;
	return fact;
}

long double power(long double x, int n) {
	long double res = 1;
	while (n > 0) {
		res = (x*res);
		n--;
	}
	return res;
}

template<class T>
auto makeSineToOrder(int k) {
  using namespace std;
	return [k](T rad) -> T {
    int terms = k;
		long double cur = rad;
		long double sine = cur;
		for (long double y = 1; y <= 2*terms; y+=2) {
			if (y > 1) {
				cur = cur * (-1.0) * rad * rad / y / (y-1);
				sine += cur; 
			}
		}
		return sine;
	};
}

int main() {
   using namespace std;
   long double pi = 3.14159265358979323846264338327950288419716939937510L;
	 for(int order = 1;order < 20; order++) {
      auto sine = makeSineToOrder<long double>(order);
      cout << "order(" << order << ") -> sine(pi) = " << setprecision(15) << sine(pi) << endl;
   }
   return 0;
}
