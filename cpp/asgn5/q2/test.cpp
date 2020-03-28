#include <memory>
#include "List.h"

void test1()
{
   using namespace std;
   cout << "Test 1" << endl;   
   List<int> aList;
   for(int i=0;i<5;i++)
      aList.insert1(i);
   aList.forEach1(std::function<void(const int&)>([](const int& v) {
            cout << v << " ";
         }));
   
   cout << endl;
   
   for(int i=10;i < 20;i++)
      aList.append1(i);

   aList.forEach1(std::function<void(const int&)>([](const int& v) {
            cout << v << " ";
         }));

   cout << endl;
}

void test2()
{
   using namespace std;
   cout << "Test 2" << endl;
   List<unique_ptr<int>> aList;
   unique_ptr<int> p(new int);
	 *p = 7;
   aList.insert(p);

   for(int i=0;i<10;i++) {
   		unique_ptr<int> p(new int);
			*p = i;
			aList.insert(p);
	 }

   aList.forEach(std::function<void(const unique_ptr<int>&)>([](const unique_ptr<int>& v) {
            cout << *v << " ";
         }));
   cout << endl;
   
   for(int i=100;i<110;i++) {
   		unique_ptr<int> p(new int);
			*p = i;
			aList.append(p);
	 }
   
   aList.forEach(std::function<void(const unique_ptr<int>&)>([](const unique_ptr<int>& v) {
            cout << *v << " ";
         }));
   cout << endl;
}

int main()
{
   test1();std::cout << std::endl;
   test2();std::cout << std::endl;
   return 0;
}
