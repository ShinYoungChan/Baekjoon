#include <iostream>
#include <vector>

using namespace std;

int map[500][500];
int dp[500][500];
int dxdy[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
int n;

int dfs(int x, int y) {
	if (dp[x][y]) return dp[x][y];
	dp[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int mx = x + dxdy[i][0];
		int my = y + dxdy[i][1];
		if (mx<0 || mx>n - 1 || my<0 || my>n - 1)continue;
		if (map[x][y] < map[mx][my]) {
			dp[x][y] = max(dp[x][y], dfs(mx, my) + 1);
		}
	}
	return dp[x][y];
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dfs(i, j);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ans < dp[i][j]) ans = dp[i][j];
		}
	}
	printf("%d\n", ans);
	return 0;
}