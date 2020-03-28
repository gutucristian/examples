#include <memory>
#include "List.h"

void test1()
{
	using namespace std;
  cout << "Test 1" << endl;   
  List<int> aList;
	for(int i=0;i<5;i++)
      aList.insert(i);
  aList.forEach(std::function<void(const int&)>([](const int& v) {
           cout << v << " ";
        }));
  
	cout << endl;
   
	for(int i=10;i < 20;i++)
      aList.append(i);

  aList.forEach(std::function<void(const int&)>([](const int& v) {
           cout << v << " ";
        }));

	cout << endl;
}

void test2()
{
   using namespace std;
   cout << "Test 2" << endl;
   List<unique_ptr<int>> aList;
   aList.insert(make_unique<int>(7));

   for(int i=0;i<10;i++) 
      aList.insert(make_unique<int>(i));

   cout << "here" << endl;

   aList.forEach(std::function<void(const unique_ptr<int>&)>([](const unique_ptr<int>& v) {
            cout << *v << " ";
         }));
   cout << endl;
   

   for(int i=100;i<110;i++) 
      aList.append(make_unique<int>(i));
   
   
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
