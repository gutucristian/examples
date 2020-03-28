#ifndef __STUDENT_H
#define __STUDENT_H

#include <string>
#include <vector>

struct Student {
   std::string fName;
   double mt,final;
   std::vector<double> hmwks;
   void readStudent();
   double overallGrade(double hwkGrade) const {
      return 0.3 * mt + 0.4 * final + 0.3 * hwkGrade;
   }
   double median() const;
   double average() const;
   void report() const;
};

#endif
