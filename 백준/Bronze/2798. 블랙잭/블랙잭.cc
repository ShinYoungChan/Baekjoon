#include <stdio.h>
#include <iostream>

using namespace std;

int main(void)
{
	int n, m, card[100];
	cin >> n >> m;
	int max = 0;
	for (int i = 0; i < n; i++)
		cin >> card[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;
			for (int k = 0; k < n; k++) {
				if (j == k || i == k)
					continue;
				int sum = 0;
				sum = card[i] + card[j] + card[k];
				if (max < sum && sum <= m) {
					max = sum;
				}
			}
		}
	}
	cout << max << endl;
	return 0;
}