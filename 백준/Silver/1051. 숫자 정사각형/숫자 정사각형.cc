#include <iostream>
#include <vector>

using namespace std;

int map[50][50];

bool rectangle(int x, int y, int size) {
	if (map[x][y] == map[x + size - 1][y] && map[x][y] == map[x][y + size - 1] && map[x][y] == map[x + size - 1][y + size - 1])
		return true;
	return false;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	int rect = n < m ? n : m;
	int ans = 0;
	while (ans == 0) {
		for (int i = 0; i <= n - rect; i++) {
			for (int j = 0; j <= m - rect; j++) {
				if (rectangle(i, j, rect)) {
					ans = rect * rect;
				}
			}
		}
		rect--;
	}
	printf("%d\n", ans);
	return 0;
}