#include <stdio.h>
#include <iostream>

using namespace std;

unsigned long long int c[60][60];

unsigned long long int combination(int n, int r)
{
	if (n == r || r == 0)
		return 1;
	if (c[n][r] != 0)
		return c[n][r];
	return c[n][r] = combination(n - 1, r - 1) + combination(n - 1, r);
}

unsigned long long int dp(int n)
{
	if (n == 1)
		return 1;
	unsigned long long int sum = 0;
	unsigned long long int result = combination(2 * n, n);
	/*int count = 0;
	for (int i = 0; i < n - 2; i++) {
		printf("combination(%d, %d)호출\n", 2 * n - 4 - i, n - 1);
		sum += combination(2 * n - 4 - i, n - 1);
		for (int j = 1; j <= i; j++) {
			printf("combination(%d, %d)호출\n", 2 * n - 4 - i - j, n - 1 - j);
			sum += combination(2 * n - 4 - i - j, n - 1 - j);
		}
	}*/
	/*int hNum = n - 1;
	while (hNum >= 2) {
		int wNum = 0;
		while (wNum < hNum - 1) {
			printf("wNum = %d, hNum = %d\n", wNum, hNum);
			printf("combination(%d, %d)호출\n", 2 * n - 2 - hNum - wNum, n - 1 - wNum);
			sum += combination(2 * n - 2 - hNum - wNum, n - 1 - wNum);
			wNum++;
		}
		hNum--;
	}*/
	int wNum = 0;
	int hNum = 1;
	while (hNum<n) {
		sum += combination(2 * n - hNum, n-hNum);
		hNum++;
		wNum++;
	}
	sum++;
	return result - sum;
}

int main(void)
{
	while (true) {
		int n;
		cin >> n;
		if (n == 0)
			break;
		cout << dp(n) << endl;
	}
}