#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dxdy[8][2] = { {-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2} };

int bfs(int n, int sx, int sy, int ex, int ey) {
	vector<vector<bool>> visit(n, vector<bool>(n, false));
	visit[sx][sy] = true;
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(sx, sy, 0));
	while (!q.empty()) {
		auto [x, y, cnt] = q.front();
		q.pop();
		if (x == ex && y == ey) {
			return cnt;
		}
		for (int i = 0; i < 8; i++) {
			int nx = x + dxdy[i][0];
			int ny = y + dxdy[i][1];
			if (nx<0 || nx>n - 1 || ny<0 || ny>n - 1 || visit[nx][ny])continue;
			visit[nx][ny] = true;
			q.push(make_tuple(nx, ny, cnt + 1));
		}
	}
}

int main() {
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		int n, sx, sy, ex, ey;
		cin >> n;
		cin >> sx >> sy;
		cin >> ex >> ey;

		int ans = bfs(n, sx, sy, ex, ey);
		printf("%d\n", ans);
	}
	return 0;
}