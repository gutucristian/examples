#include "wList.H"
#include <iostream>

list<string> *buildList(istream& input) {
	list<string> *lst = new list<string>;
	string word;
	while (true) {
		cin >> word;
		if (cin.eof()) break;
		lst->push_back(word);
	}

	return lst;
}

