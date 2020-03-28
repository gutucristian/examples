#include <iostream>
#include <stack>

using namespace std;

void get_factors(long n, stack<long>& s) {
  for (long i = 2; i <= n; i++) {
    while (n % i == 0) {
      s.push(i);
      n /= i;
    }
  }
}

void print_factors(stack<long> s) {
  while (!s.empty()) {
    cout << s.top() << ' ';
		s.pop();
  }
  cout << endl;
}

int main()
{
  stack<long> s;
  int n;
	cout << "Enter a number to factor: ";
  cin >> n;
  get_factors(n, s);
  print_factors(s);
  return 0;
}

