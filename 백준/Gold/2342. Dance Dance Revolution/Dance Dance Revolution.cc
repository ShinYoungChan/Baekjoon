#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

vector<int> v;
int ans = 210000000;
int dp[100001][5][5];

int move(int leg, int dis) {
	if (leg == 0)
		return 2;
	else if (leg == dis)
		return 1;
	else if (abs(leg - dis) != 2)
		return 3;
	return 4;
}

int main(void) {
	int a;
	while (true) {
		cin >> a;
		v.push_back(a);
		if (a == 0)break;
	}
	for (int i = 0; i < 100001; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++)
				dp[i][j][k] = 2100000000;
		}
	}
	dp[0][0][0] = 0;
	for (int i = 1; i < v.size(); i++) {
		int tmp = v[i - 1];
		for (int left = 0; left < 5; left++) {
			for (int right = 0; right < 5; right++) {
				dp[i][left][tmp] = min(dp[i][left][tmp], dp[i - 1][left][right] + move(right, tmp));
				dp[i][tmp][right] = min(dp[i][tmp][right], dp[i - 1][left][right] + move(left, tmp));
			}
		}
	}
	int ans = 2100000000;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			ans = min(ans, dp[v.size()-1][i][j]);
		}
	}
	cout << ans << endl;
	return 0;
}