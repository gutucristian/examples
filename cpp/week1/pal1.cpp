#include <iostream>
#include <string>

using namespace std;

int main()
{
   /*
    * This program is supposed to take (on the standard input) a string (C++)
    * and produce on its standard output a yes/no answer depending on 
    * whether the string is indeed a palindrome (reads the same both forward
    * and backward. 
    * For this second version, stick to plain C to write the code. Make sure 
    * you are robust against all inputs (length of words). The purpose of the
    * exercice is to build appreciation for how much C++ automates for you.
    * Clearly, don't rely on a compile-time fixed array of characters...
    * Introduce sub-rountines as necessary. 
    */
	string input;
	cin >> input;
	
	if (equal(input.begin(), input.begin() + input.size()/2, input.rbegin())) {
		cout << "yes" << endl;
	} else {
		cout << "no" << endl;
	}

	return 0;
}
