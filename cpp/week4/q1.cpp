#include <vector>
#include <iostream>

using namespace std;

double increment(const double d) {
   return d+1;
}

template <class T>;
std::ostream& operator<<(std::ostream& os,const std::vector<T>& c) {
   for(auto v : c)
      os << v << " ";
   return os;
}

template <class Container, class Mapper>
Container map1(const Container& vec, Mapper func) {
	Container result;
	for (const auto& elem: vec) {
		result.push_back(func(elem));
	}
	return result;
}

template <class Container, typename Container::value_type T (*func)(const T&)>
Container map3(const Container& vec, Mapper func) {
	Container result;
	for (const auto& elem: vec) {
		result.push_back(func(elem));
	}
	return result;
}

int main()
{
   using namespace std;
   vector<double> x = {1.23, 4.56, 7.89, 0.12, 3.45, 6.78, 9.01, 2.34, 5.67, 8.90};
   vector<string> y = {"Hello", "darkness,", "my", "old", "friend.",
                       "I've", "come", "to", "talk", "with", "you", "again."};
   
   cout << x << endl;
   cout << y << endl;

   // In the code below the notation A/B should be read as follows
   // A refers to the fact that the map function uses
   //  - C: a COMPILE TIME composition or
   //  - RT: a runtime composition via templating of type
   //  - RF: a runtime composition via function type
   // B refers to the fact that the map API or the map implementation uses:
   //  - I: iterarors for specifying the range to operate on, or
   //  - C: the entire container. 


   // ======================================================================
   // Vector container
   // runtime / whole container  (feeding a function) 
   cout << "RT/C  ==> " << map0(x, increment) << endl;

   // ======================================================================
   // ANY Container
   //  runtime / whole container  (feeding a function)
   cout << "RT/C  ==> " << map1(x, increment) << endl;

   // ======================================================================
   // ANY Container
   // compile time / whole container
    cout << "C/C  ==> " << map2<vector<double>,increment>(x) << endl;
   // ======================================================================
   // ANY Container
   // runtime / whole container  (feeding a closure)
    cout << "RT/C  ==> " << map1(x, [](double v) { return v + 1;}) << endl;

   // ======================================================================
   // Runtime (function) / Iterator
   vector<double> temp0;
   map3(x.begin(),
        x.end(),
        back_inserter(temp0),
        std::function<double(double)>([](double v) { return v + 1;}));
   cout << "RF/I  ==> " << temp0 << endl;
   // ======================================================================
   // Runtime (function) /  whole container
   cout << "RF/C  ==> " << map4(x,std::function<double(double)>([](double v) {
            return v + 1;})
      ) << endl;


   // ======================================================================
   // Runtime (template) / Iterator
   vector<double> temp1;
   map5(x.begin(),
        x.end(),
        back_inserter(temp1),
        [](double v) { return v + 1;});
   cout << "RT/I  ==> " << temp1 << endl;
 
   // ======================================================================
   // Runtime (template) /  whole container
   cout << "RT/C  ==> " << map6(x,[](double v) { return v + 1;}) << endl;
   return 0;
}
