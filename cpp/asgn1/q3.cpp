#include <iostream>
#include <vector>

using namespace std;

void get_factors(long n, vector<long>& lst) {
  for (long i = 2; i <= n; i++) {
    while (n % i == 0) {
			lst.push_back(i);
      n /= i;
    }
  }
}

void print_factors(vector<long>& lst) {
	for(long x: lst) {
		cout << x << ' ';
	}
	cout << endl;
}

int main()
{
  vector<long> lst;
	long n;
	cout << "Enter a number to factor: ";
  cin >> n;
  get_factors(n, lst);
	print_factors(lst);
  return 0;
}

