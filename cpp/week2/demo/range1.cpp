#include <iostream>
#include <string>

int main()
{
   using namespace std;
   string vals = {'H','e','l','l','o'};
   for(char v : vals) {
      cout << "v = " << v << endl;
   }
   cout << "Old" << endl;
   for(int k=0;k < vals.size(); k++) {
      cout << "v = " << vals[k] << endl;
   }
   return 0;   
}
