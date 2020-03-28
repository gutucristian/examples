#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

template <typename T> std::ostream& operator<< (std::ostream& out, const std::vector<T>& v)
{
  if ( !v.empty() ) {
    out << '[';
    std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
    out << "\b\b]";
  }
  return out;
}

template <typename T>
void mergeSortAux(std::vector<T>& v,
                  typename std::vector<T>::iterator from,
                  typename std::vector<T>::iterator to,
                  std::function<bool(T&,T&)> const& cmp)
{
   // [from, to )  
   if (next(from) == to) {
      return;
   } else {
      auto d = from + (to - from)/2;
      mergeSortAux(v,from,d,cmp);
      mergeSortAux(v,d,to,cmp);
      std::vector<T> a(from,d),b(d,to);
      
      auto i = a.begin(),j = b.begin(),k = from;
      while (i != a.end() && j != b.end()) {
         if (cmp(*i,*j))
            *k++ = *i++;
         else *k++ = *j++;
      }
      while (i != a.end()) *k++ = *i++;
      while (j != b.end()) *k++ = *j++;
   }
}

template <typename T>
void mergeSort(std::vector<T>& v,std::function<bool(T&,T&)> cmp)
{
   return mergeSortAux(v,v.begin(),v.end(),cmp);
}
 
int main()
{
   using namespace std;
   vector<int> uv = {1, 30, -4, 3, 5, -4, 1, 6, -8, 2, -5, 64, 1, 92};
   cout << "init:\t" << uv << endl;
   std::function<bool(int&,int&)> c = [](int& a,int& b) { return a<b;};
   //mergeSort(uv,c);
   mergeSort(uv,std::function<bool(int&,int&)>([](int& a,int& b)-> bool { return a<b;}));
   cout << "sort:\t" << uv << endl;
}
