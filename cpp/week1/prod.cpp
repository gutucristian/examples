#include <iostream>

using namespace std;
float prod(int k) {
	float result = 1;
	for (float i = 2; i <= k; i++) {
		result *= (1 - (1/i)); 
	}
	return result;
}

int main()
{
  /*
   * This program is supposed to
   * - take a positive integer k as input (>= 2)
   * - produce as output the value prod(i in 2..k) (1-1/k)
   * Consider an iterative implementation
   * Consider a recursive implementation
   */
	int k;
	cin >> k;
	if (k < 2) {
		return 1;
	}
	cout << prod(k) << endl;
  return 0;
}
