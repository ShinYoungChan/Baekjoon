#include <iostream>
#include <stack>

using namespace std;

int map[501][501];
int paintsize = 0;
int dxdy[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };

bool dfs(int i, int j, int n, int m) {
	if (map[i][j] != 1)
		return false;

	int scale = 1;
	stack<pair<int,int>> s;
	map[i][j] = 2;
	s.push({ i,j });
	while (!s.empty()) {
		int x = s.top().first;
		int y = s.top().second;
		s.pop();
		for (int k = 0; k < 4; k++) {
			int mx = x + dxdy[k][0];
			int my = y + dxdy[k][1];
			if (mx<0 || mx>n - 1 || my<0 || my>m - 1)continue;
			if (map[mx][my] == 1) {
				s.push({ mx,my });
				map[mx][my] = 2;
				scale++;
			}
		}
	}
	paintsize = paintsize > scale ? paintsize : scale;
	return true;
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int paint = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && dfs(i, j, n, m)) {
				paint++;
			}
		}
	}
	printf("%d\n%d\n", paint, paintsize);
	return 0;
}