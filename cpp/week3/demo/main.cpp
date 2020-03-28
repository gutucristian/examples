#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;
int main()
{
   // Accelerated C++ : Chapter 3 - page 36
   string fName;
   cout << "First name? ";
   cin >> fName;
   cout << "Good morning " << fName
        << "! Please enter your midterm and final: "
        << "(hit return after the two numbers)";
      
   double mt,final;
   cin >> mt >> final;

   cout << "Now enter your homeworks --hit EOF (CTRL-D) at the end--:";
   vector<double> hmwks;
   double x;
   while (cin >> x) {
      hmwks.push_back(x);      
   }
   double ttl = 0;
   for(double h : hmwks) ttl += h;
   vector<double>::size_type sz = hmwks.size();
   double overall = 0.3 * mt + 0.4 * final + 0.3 * ttl / sz;
   auto oldp = cout.precision();
   cout << "Your overall grade is: "
        << setprecision(4) << overall
        << setprecision(oldp) << endl;
   return 0;
}
