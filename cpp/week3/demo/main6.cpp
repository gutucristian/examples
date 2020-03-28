#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct Student {
   string fName;
   double mt,final;
   vector<double> hmwks;
   void readStudent();
   double overallGrade() const;
};

void Student::readStudent() {
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
}

double Student::overallGrade() const
{
   double ttl = 0;
   for(double h : hmwks) ttl += h;
   vector<double>::size_type sz = hmwks.size();
   return 0.3 * mt + 0.4 * final + 0.3 * ttl / sz;
}

void studentReport(const Student& st)
{
   auto oldp = cout.precision();
   cout << "Your overall grade is: "
        << setprecision(4) << st.overallGrade()
        << setprecision(oldp) << endl;   
}

int main()
{
   Student st;
   st.readStudent();
   studentReport(st);
   return 0;
}
