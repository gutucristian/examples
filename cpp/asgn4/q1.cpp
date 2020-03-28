#include <vector>
#include <iostream>
#include <functional>

template <class InputIt, class Transform>
void forEach(InputIt from, InputIt to, const Transform& f) {
	while (from != to)
		f(*from++);
}

template<class InputIt, class T, class Transform>
T reduce(InputIt from, InputIt to, T base, const Transform& f) {
	T res = base;
	while (from != to)
		res = f(res, *from++);
	return res;
}

template<class InputIt, class T, class Transform>
T foldr(InputIt from, InputIt to, T base, const Transform& f) {
	T res = base;
	while (--to >= from) {
		res = f(*to, res);
	}
	return res;			
}

template<class InputIt, class OutputIt, class Transform>
void advanced(InputIt from, InputIt to, OutputIt dest, const Transform& f) {
	while (from != to) {
		if (f(*from)) *dest++ = *from;
		from++;
	}
}

template<class Container, class Transform>
Container filter(const Container& c, const Transform& f) {
	Container res;
	advanced(c.begin(), c.end(), back_inserter(res), f);
	return res;
}

template <class T>
std::ostream& operator<<(std::ostream& os,const std::vector<T>& c)
{
   forEach(c.begin(),c.end(),[&os](T val) { os << val << " ";});
   return os;
}

int main()
{
   using namespace std;
   vector<double> x = {1.23, 4.56, 7.89, 0.12, 3.45, 6.78, 9.01, 2.34, 5.67, 8.90};
   vector<string> y = {"Hello", "darkness,", "my", "old", "friend.",
                       "I've", "come", "to", "talk", "with", "you", "again."};
   
   //  for each
   cout << x << endl;
   cout << y << endl;

   cout << "> 5 = "
        << filter(x,[](double v) { return v > 5.0;}) << endl;
   
   cout << "Sum = "
        << reduce(x.begin(),x.end(),0.0,[](double acc,double v) { return acc + v;}) << endl;
   
   cout << "Sum = "
        << foldr(x.begin(),x.end(),0.0,[](double acc,double v) { return acc + v;}) << endl;
   return 0;
}
