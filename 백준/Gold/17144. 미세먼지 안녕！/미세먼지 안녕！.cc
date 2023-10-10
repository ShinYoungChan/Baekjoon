#include <iostream>
#include <vector>

using namespace std;

int r, c, t;
int map[1000][1000], copymap[1000][1000];
int dxdy[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
pair<int, int> high, low;

void spread(int x, int y) {
	int cnt = 0;
	int spreadDust = map[x][y] / 5;
	for (int i = 0; i < 4; i++) {
		int mx = x + dxdy[i][0];
		int my = y + dxdy[i][1];
		if (mx<0 || mx>r - 1 || my<0 || my>c - 1 || map[mx][my] == -1)continue;
		copymap[mx][my] += spreadDust;
		cnt++;
	}
	copymap[x][y] += map[x][y] - spreadDust * cnt;
}

void dust() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] > 0) {
				spread(i, j);
			}
		}
	}
}

void air() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			map[i][j] = copymap[i][j];
		}
	}
	int x = high.first - 1;
	int y = high.second;
	int dir = 0;
	while (true) {
		int mx = x - dxdy[dir][0];
		int my = y - dxdy[dir][1];
		if (x == high.first && y == high.second) break;
		if (x == 0 && y == 0) dir = 3;
		if (x == 0 && y == c - 1)dir = 2;
		if (x == high.first && y == c - 1) dir = 1;
		if (mx == high.first && my == high.second) {
			map[x][y] = 0;
		}
		else {
			map[mx][my] = copymap[x][y];
			map[x][y] = 0;
		}
		x += dxdy[dir][0];
		y += dxdy[dir][1];
	}
	x = low.first + 1;
	y = low.second;
	dir = 2;
	while (true) {
		int mx = x - dxdy[dir][0];
		int my = y - dxdy[dir][1];
		if (x == low.first && y == low.second) break;
		if (x == r - 1 && y == 0) dir = 3;
		if (x == r - 1 && y == c - 1)dir = 0;
		if (x == low.first && y == c - 1) dir = 1;
		if (mx == low.first && my == low.second) {
			map[x][y] = 0;
		}
		else {
			map[mx][my] = copymap[x][y];
			map[x][y] = 0;
		}
		x += dxdy[dir][0];
		y += dxdy[dir][1];
	}
	map[high.first][high.second] = -1;
	map[low.first][low.second] = -1;
}

void reset() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			copymap[i][j] = 0;
	}
}

int main() {
	cin >> r >> c >> t;
	bool flag = false;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1 && !flag) {
				high.first = i; high.second = j; flag = true;
			}
			else if (map[i][j] == -1 && flag) {
				low.first = i; low.second = j;
			}
		}
	}
	while (t--) {
		// 1. 확산
		dust();
		// 2. 공기청정기 작동
		air();
		reset();
	}

	int ans = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] > 0) ans += map[i][j];
		}
	}
	printf("%d\n", ans);
	return 0;
}