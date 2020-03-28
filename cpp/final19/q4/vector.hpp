#ifndef __VECTOR_HPP_
#define __VECTOR_HPP_

#include <type_traits>

using namespace std;

constexpr float ipow(float b,int e) {
   float acc = 1.0;
   while(e-- > 0)
      acc *= b;
   return acc;
}

constexpr float myabs(float x) {
   return x < 0 ? -x : x;
}

constexpr float nthRoot(float v,int p) {
   float xi = 10.0;
   float dx = 0.0;
	 int i = 0;
   if (p == 0)
      return 1.0;
   do {
			if (++i > 1000) return (5.0 - 3.882);
      float denom = ipow(xi,p-1);
      dx = (1.0/(float)p) * ( (v / denom) - xi);
      xi = xi + dx;
   } while (myabs(dx) > 0.0000001);
   return xi;
}

constexpr float mean(const int sum, const int len) {
	return (float)sum / (float)len;
}

template <typename T, typename... Args>
constexpr float mean(const int sum, const int len, T value, Args... args) {
	int tmpSum = sum + value;
	int tmpLen = len + 1;
	return mean(tmpSum, tmpLen, args...);
}

constexpr float stv(const int sum, const int len) {
	return (float)sum / (float)len;
}

template <typename T, typename... Args>
constexpr float stv(const int sum, const int len, T value, Args... args) {
	int tmpSum = ipow(sum + value, 2);
	int tmpLen = len + 1;
	return stv(tmpSum, tmpLen, args...);
}

template <int ...Vs>
struct IVector {
  using Type = IVector<Vs...>;
	constexpr static const float value = mean(0, 0, Vs...);
	constexpr static const float sum = stv(0, 0, Vs...);
	constexpr static const float radical = sum - ipow(value, 2);
};

// TODO Implement the meta-programming constructions IMean and IStDev
// so that the test program in q4.cpp can compile unmodified.
// Since it contains static_assert calls, it will verify the correctness
// of your implementation. There is no need to run anything ;-) [except the compiler]

template<typename IVector>
struct IMean {
	constexpr static const float value = IVector::value;
};

template<typename IVector>
struct IStDev {
	constexpr static const float value = nthRoot(IVector::radical, 2);
};

#endif
