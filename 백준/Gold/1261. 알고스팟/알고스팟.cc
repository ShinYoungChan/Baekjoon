#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

int bfs(vector<vector<int>>& map, vector<vector<bool>>& visit, int n, int m) {
	priority_queue<tuple<int, int, int>> pq;
	int dxdy[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
	visit[0][0] = true;
	pq.push(make_tuple(0, 0, 0));	// cnt, x, y
	while (!pq.empty()) {
		auto [cnt, x, y] = pq.top();
		cnt *= -1;
		pq.pop();
		if (x == n && y == m) {
			return cnt;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dxdy[i][0];
			int ny = y + dxdy[i][1];
			if (nx<0 || nx>n || ny<0 || ny>m || visit[nx][ny]) continue;
			if (map[nx][ny] == 0) {
				pq.push(make_tuple(-cnt, nx, ny));
			}
			else if (map[nx][ny] == 1) {
				pq.push(make_tuple(-(cnt + 1), nx, ny));
			}
			visit[nx][ny] = true;
		}
	}
}

int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>> map(n, vector<int>(m, 0));
	vector<vector<bool>> visit(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			map[i][j] = str[j] - '0';
		}
	}
	printf("%d\n", bfs(map, visit, n - 1, m - 1));
	return 0;
}