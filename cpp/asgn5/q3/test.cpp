#include "List.h"

void test()
{
   using namespace std;
   List<int> aList;
   shared_ptr<List<int>::Node> loc = aList.insert(-99);
   for(int i=0;i<5;i++)
      aList.insert(i);
   for(int i=10;i < 20;i++)
      aList.append(i);

   cout << "BEFORE LOOP" << endl;
   for(auto k : aList)
      cout << k << " ";   
   cout << endl;
   aList.change(loc,9999);

   for(auto k : aList)
      cout << k << " ";
   cout << endl;

   // REuse STL for_each on new container. 
   for_each(aList.begin(),aList.end(),[](int v) {
         cout << v << " ";
      });  
   cout << endl;
}

void test1()
{
   using namespace std;
   List<unique_ptr<int>> aList;
   for(int i=0;i<10;i++) {
      aList.insert(make_unique<int>(i));
   }
   for(int i=100;i<110;i++) {
      aList.append(make_unique<int>(i));
   }
   for(const unique_ptr<int>& k : aList) {
      cout << *k << " ";
   }
   cout << endl;
}

int main()
{
   test();std::cout << std::endl;
   test1();std::cout << std::endl;
   return 0;
}
