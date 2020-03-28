#include "wList.H"
#include <iostream>

void buildList(list<string>& lst, istream& input) {
	using namespace std;

	string word;
	
	while (true) {
		cin >> word;
		if (cin.eof()) break;
		
		for (char c: word) {
			if (!isalnum(c)) throw std::string("input has non alphanumeric character");
		}

		lst.push_back(word);
	} 

	return;
}
