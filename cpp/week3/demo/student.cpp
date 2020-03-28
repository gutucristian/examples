#include "student.H"
#include <iostream>
#include <iomanip>

using namespace std;

void Student::readStudent()
{
   cout << "First name? ";
   cin >> fName;
   cout << "Good morning " << fName
        << "! Please enter your midterm and final: "
        << "(hit return after the two numbers)";      
   cin >> mt >> final;
   cout << "Now enter your homeworks --hit EOF (CTRL-D) at the end--:";
   double x;
   while (cin >> x)  
      hmwks.push_back(x);
   sort(hmwks.begin(),hmwks.end());
}

double Student::median() const
{
   auto sz = hmwks.size();
   if (sz % 2 == 0)
      return (hmwks[sz/2 - 1] + hmwks[sz/2])/2;
   else return hmwks[sz/2];
}

double Student::average() const
{
   double ttl = 0;
   for(double h : hmwks) ttl += h;
   auto sz = hmwks.size();
   return ttl/sz;
}

void Student::report() const
{
   auto oldp = cout.precision();
   auto gr = overallGrade(median());
   cout << "Your overall grade is: "
        << setprecision(6)
        << gr << setprecision(oldp) << endl;   
}
