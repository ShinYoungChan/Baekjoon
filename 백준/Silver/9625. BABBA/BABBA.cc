#include <iostream>

using namespace std;

int fib[46];

int main() {
	int k;
	cin >> k;
	fib[0] = 0, fib[1] = 1;
	for (int i = 2; i <= k; i++) {
		fib[i] = fib[i - 2] + fib[i - 1];
	}
	printf("%d %d\n", fib[k - 1], fib[k]);
	return 0;
}