#include "UF.h"

#include <iostream>

int main()
{
   using namespace std;
   UnionFind<int> uf;

   shared_ptr<UnionFind<int>::Node> t[20];
   for(int i=0;i<20;i++)
      t[i] = uf.makeSet(i);

   uf.merge(t[2],t[3]);
   uf.merge(t[4],t[5]);
   uf.merge(t[5],t[2]);
   uf.merge(t[1],t[5]);

   shared_ptr<UnionFind<int>::Node> t3 = uf.setFor(t[5]);

   cout << "T3:" << t3 << endl;
   
   for(int i=0;i<20;i++)
      cout << t[i] << endl;
   return 0;
}
