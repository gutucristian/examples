#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct Student {
   string fName;
   double mt,final;
   vector<double> hmwks;   
};

Student readStudent() {
   Student st;
   cout << "First name? ";
   cin >> st.fName;
   cout << "Good morning " << st.fName
        << "! Please enter your midterm and final: "
        << "(hit return after the two numbers)";      
   cin >> st.mt >> st.final;
   cout << "Now enter your homeworks --hit EOF (CTRL-D) at the end--:";
   double x;
   while (cin >> x)  
      st.hmwks.push_back(x);         
   return st;
}

void studentReport(const Student& st)
{
   double ttl = 0;
   for(double h : st.hmwks) ttl += h;
   vector<double>::size_type sz = st.hmwks.size();
   double overall = 0.3 * st.mt + 0.4 * st.final + 0.3 * ttl / sz;
   auto oldp = cout.precision();
   cout << "Your overall grade is: "
        << setprecision(4) << overall
        << setprecision(oldp) << endl;   
}

int main()
{
   Student st = readStudent();
   studentReport(st);
   return 0;
}
