#include <iostream>
#include <vector>

using namespace std;

int n, m, h, ans;
int map[100][11];

bool check() {
	for (int i = 0; i <= n * 2 - 2; i += 2) {
		int pos = i;
		for (int j = 0; j < h; j++) {
			if (map[j][pos + 1] == 1) {
				pos += 2;
			}
			else if (map[j][pos - 1] == 1) {
				pos -= 2;
			}
		}
		if (pos != i) return false;
	}
	return true;
}

void dfs(int count, int x, int y) {
	if (count > ans || count > 3) return;
	if (check()) {
		if (ans > count) ans = count; return;
	}
	for (int i = x; i <= h; i++) {
		for (int j = y; j < n * 2 - 2; j++) {
			if (j & 1) {
				if (map[i][j] == 0 && map[i][j - 2] == 0 && map[i][j + 2] == 0) {
					map[i][j] = 1;
					dfs(count + 1, i, j);
					map[i][j] = 0;
				}
			}
		}
		y = 1;
	}
}

int main() {
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a - 1][b * 2 - 1] = 1;
	}
	ans = 4;
	dfs(0, 0, 0);
	if (ans == 4) ans = -1;
	printf("%d\n", ans);
	return 0;
}