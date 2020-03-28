#include "wList.H"
#include <list>
#include <iostream>

using namespace std;

void print_list(const list<string> *lst) {
	for (string x: *lst) {
		cout << x << endl;
	}
	return;
}

int main()
{
	list<string> *lst = buildList(cin);
	print_list(lst);
	delete lst;
	return 0;
}
