#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d[30][30];

int combination(int n, int r)
{
	if (n == r || r == 0)
		return 1;
	if (d[n][r] != 0)
		return d[n][r];
	return d[n][r] = combination(n - 1, r - 1) + combination(n - 1, r);
}

int main(void)
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, r;
		cin >> n >> r;
		if (n < r) {
			int tmp = n;
			n = r;
			r = tmp;
		}
		cout << combination(n, r) << endl;
	}
	return 0;
}