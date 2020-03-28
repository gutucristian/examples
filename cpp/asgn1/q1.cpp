#include <iostream>

using namespace std;

void print_factors(long n) {
  for (long i = 2; i <= n; i++) {
    while (n % i == 0) {
      cout << i << ' ';
      n /= i;
    }
  }
  cout << endl;
}

int main()
{
  long n;
	cout << "Enter a number to factor: ";
  cin >> n;
  print_factors(n);
  return 0;
}

