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
   void report() const;
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

   sort(hmwks.begin(),hmwks.end());
}

double Student::overallGrade() const
{
   auto sz = hmwks.size();
   double med;
   if (sz % 2 == 0)
      med = (hmwks[sz/2 - 1] + hmwks[sz/2])/2.0;
   else med = hmwks[sz/2];
   return 0.3 * mt + 0.4 * final + 0.3 * med;
}

void Student::report() const
{
   auto oldp = cout.precision();
   cout << "Your overall grade is: "
        << setprecision(4) << overallGrade()
        << setprecision(oldp) << endl;   
}

int main()
{
   Student st;
   st.readStudent();
   st.report();
   return 0;
}
