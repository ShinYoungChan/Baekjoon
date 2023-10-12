#include <iostream>
#include <vector>

using namespace std;

class seafood{
public:
	int x, y, dir, die;
public:
	seafood() {
		x = 0, y = 0, dir = 0, die = 0;
	}
};

int dxdy[8][2] = { {-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1} };
int ans = 0;

void dfs(int map[4][4], seafood fish[17], int x, int y, int sum) {
	// 배열 복사
	int copymap[4][4];
	seafood copyfish[17];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			copymap[i][j] = map[i][j];
		}
	}
	for (int i = 1; i <= 16; i++) {
		copyfish[i] = fish[i];
	}
	// 먹고
	int fish_number = copymap[x][y];
	int shark_dir = copyfish[fish_number].dir;
	copyfish[fish_number].die = 1;
	copymap[x][y] = -1;
	sum += fish_number;
	if (ans < sum) ans = sum;
	// 물고기 이동
	for (int i = 1; i <= 16; i++) {
		if (copyfish[i].die) continue;

		int fx = copyfish[i].x;
		int fy = copyfish[i].y;
		int dir = copyfish[i].dir;

		int mx = fx + dxdy[dir][0];
		int my = fy + dxdy[dir][1];
		int md = dir;
		while (mx < 0 || mx>3 || my < 0 || my>3 || (mx == x && my == y)) {
			md = (md + 1) % 8;
			mx = fx + dxdy[md][0];
			my = fy + dxdy[md][1];
		}
		if (copymap[mx][my] != -1) {
			int target = copymap[mx][my];
			copyfish[target].x = fx;
			copyfish[target].y = fy;
			copyfish[i].x = mx;
			copyfish[i].y = my;
			copyfish[i].dir = md;

			copymap[mx][my] = i;
			copymap[fx][fy] = target;
		}
		else {
			copyfish[i].x = mx;
			copyfish[i].y = my;
			copyfish[i].dir = md;

			copymap[mx][my] = i;
			copymap[fx][fy] = -1;
		}
	}
	// 상어 이동
	for (int step = 1; step <= 3; step++) {
		int sx = x + dxdy[shark_dir][0] * step;
		int sy = y + dxdy[shark_dir][1] * step;
		if (sx < 0 || sx>3 || sy < 0 || sy>3)break;
		if (copymap[sx][sy] != -1) {
			dfs(copymap, copyfish, sx, sy, sum);
		}
	}
}

int main() {
	int dir;
	int map[4][4];
	seafood fish[17];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> map[i][j] >> dir;
			fish[map[i][j]].x = i;
			fish[map[i][j]].y = j;
			fish[map[i][j]].dir = dir - 1;
		}
	}
	dfs(map, fish, 0, 0, 0);
	printf("%d\n", ans);
	return 0;
}