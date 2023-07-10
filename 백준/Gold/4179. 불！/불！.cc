#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

vector<string> map;
bool visit[2][1000][1000];
queue<pair<int, int>> q[2][2];
int r, c;
int dxdy[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
bool escape = false;

void bfs(int flag, int curr) {
	int next = curr ^ 1;
	while (!q[flag][curr].empty()) {
		int x = q[flag][curr].front().first;
		int y = q[flag][curr].front().second;
		q[flag][curr].pop();
		if (flag == 0 && map[x][y] == 'F')continue;
		for (int i = 0; i < 4; i++) {
			int mx = x + dxdy[i][0];
			int my = y + dxdy[i][1];
			if (flag == 0 && (mx<0 || mx>r - 1 || my<0 || my>c - 1)) {
				escape = true; break;
			}
			if (flag && (mx<0 || mx>r - 1 || my<0 || my>c - 1))continue;
			if (visit[flag][mx][my] || map[mx][my] == '#')continue;
			if (flag == 0 && map[mx][my] == 'F')continue;
			visit[flag][mx][my] = true;
			q[flag][next].push(make_pair(mx, my));
			if (flag) {
				map[mx][my] = 'F';
			}
		}
	}
}

int main() {
	cin >> r >> c;
	map.resize(r);
	for (int i = 0; i < r; i++) {
		cin >> map[i];
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 'J') {
				q[0][0].push(make_pair(i, j));
			}
			if (map[i][j] == 'F') {
				q[1][0].push(make_pair(i, j));
			}
		}
	}
	int curr = 0, time = 0;
	while (true) {
		bfs(0, curr);
		bfs(1, curr);
		curr ^= 1;
		time++;
		if (escape) break;
		if (q[0][0].size() == 0 && q[0][1].size() == 0)break;
	}
	if (escape) {
		printf("%d\n", time);
	}
	else {
		printf("IMPOSSIBLE\n");
	}
	return 0;
}