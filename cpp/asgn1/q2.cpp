#include <iostream>

using namespace std;

int get_factors(long n, long (&lst)[256]) {
  int index = 0;
  for (long i = 2; i <= n; i++) {
    while (n % i == 0) {
      lst[index] = i;
      index++;
      n /= i;
    }
  }
  return index;
}

void print(long (&lst)[256], int k) {
  for (int i = 0; i < k; i++) {
    cout << lst[i] << ' ';
  }
  cout << endl;
}

int main()
{
  long buf[256] = {0};
  long n;
	cout << "Enter a number to factor: ";
  cin >> n;
  int k = get_factors(n, buf);
  print(buf, k);
  return 0;
}

