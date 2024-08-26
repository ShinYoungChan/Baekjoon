#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#define INF 100000

using namespace std;

int n, ex, ey;
int dxdy[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };	// 상 우 하 좌
vector<string> map;
queue<tuple<int,int,int>> q;
int visit[50][50][4];

int bfs() {

	while (!q.empty()) {
		auto [x, y, dir] = q.front();
		q.pop();

		int nx = x + dxdy[dir][0];
		int ny = y + dxdy[dir][1];
		int d1 = (dir + 1) % 4, d2 = (dir + 3) % 4;

		if (nx<0 || nx>n - 1 || ny<0 || ny>n - 1)continue;
		if (map[nx][ny] == '*')continue;
		// 거울 설치 지점
		if (map[nx][ny] == '!') {
			// 거울 설치 안함.
			if (visit[nx][ny][dir] > visit[x][y][dir]) {
				visit[nx][ny][dir] = visit[x][y][dir];
				q.push(make_tuple(nx, ny, dir));
			}
				
			// 거울 설치 함.
			if (visit[nx][ny][d1] > visit[x][y][dir] + 1) {
				visit[nx][ny][d1] = visit[x][y][dir] + 1;
				q.push(make_tuple(nx, ny, d1));
			}

			if (visit[nx][ny][d2] > visit[x][y][dir] + 1) {
				visit[nx][ny][d2] = visit[x][y][dir] + 1;
				q.push(make_tuple(nx, ny, d2));
			}
				
		}
		// 거울 아닌 지점
		else if (map[nx][ny] == '.') {
			if (visit[nx][ny][dir] > visit[x][y][dir]) {
				visit[nx][ny][dir] = visit[x][y][dir];
				q.push(make_tuple(nx, ny, dir));
			}
		}
		// 도착 지점
		else if (map[nx][ny] == '#') {
			if (visit[nx][ny][dir] > visit[x][y][dir]) {
				visit[nx][ny][dir] = visit[x][y][dir];
			}
		}
	}

	int ans = INF;

	for (int i = 0; i < 4; i++) {
		if (ans > visit[ex][ey][i]) {
			ans = visit[ex][ey][i];
		}
	}
	return ans;
}

void Init() {
	cin >> n;
	map.resize(n);

	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			for (int k = 0; k < 4; k++) {
				visit[i][j][k] = INF;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cin >> map[i];
		for (int j = 0; j < n; j++) {
			if (map[i][j] == '#') {
				if (q.size() == 0) {
					for (int k = 0; k < 4; k++) {
						q.push(make_tuple(i, j, k));
						visit[i][j][k] = 0;
					}
				}
				else {
					ex = i, ey = j;
				}
			}
		}
	}
}

int main() {
	Init();
	int ans = bfs();
	printf("%d\n", ans);
	return 0;
}