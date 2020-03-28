#include <iostream>
#include <vector>

using namespace std;

void get_factors(long n, vector<long>& lst) {
	if (n > 1) {
  	for (long i = 2; i <= n; i++) {
  	  while (n % i == 0) {
				lst.push_back(i);
  	    n /= i;
  	  }
  	}
	}
}

void print_factors(long n, vector<long>& lst) {
	vector<long>::size_type len = lst.size();
	if (len == 1) {		
		cout << "The prime factors of " << n << " is " << lst[0] << '.' << endl;
	} else {
		cout << "The prime factors of " << n << " are ";
		for(long i = 0; i < len; i++) {
			if (i == len-1) {
				cout << lst[i] << '.' << endl;;
			} else {
				cout << lst[i] << ' ';
			}
			if (i == len-2) {
				cout << "and ";
			}
		}
	}

}

int main()
{
  vector<long> lst;
	long n;
	cout << "Enter a number to factor: ";
  cin >> n;
  get_factors(n, lst);
	if (lst.size() > 0) 
		print_factors(n, lst);
  return 0;
}

