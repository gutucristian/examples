#include "wList.H"
#include <string>
#include <list>
#include <iostream>

void printList(const list<string>& lst) {
	for (string x: lst) {
		cout << x << endl;
	}
}

int main()
{
	using namespace std;
	try {
		list<string> lst;
		buildList(lst, cin);
		printList(lst);
	} catch (string& s) {
		cout << "Error: " << s << endl;
		return 1;
	}
	return 0;
}
