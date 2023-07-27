#include <stdio.h>
#include <iostream>

using namespace std;

long long int dp[91][2];

int main(void)
{
	int N;
	cin >> N;
	dp[1][1] = 1;
	dp[1][0] = 0;
	for (int i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}
	long long int sum = 0;
	for (int i = 0; i < 2; i++)
		sum += dp[N][i];
	cout << sum << endl;
	return 0;
}