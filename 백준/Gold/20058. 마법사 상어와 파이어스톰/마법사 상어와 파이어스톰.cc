#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int n, q, powN;
int map[64][64], temp[64][64];
bool visit[64][64];
int dxdy[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };

void rotate(int r, int c, int size) {
	int y = c + size - 1;
	for (int i = r; i < r + size; i++) {
		int x = r;
		for (int j = c; j < c + size; j++) {
			//printf("i = %d, j = %d, ri = %d, rj = %d\n", i, j, x, y);
			temp[x][y] = map[i][j];
			x++;
		}
		y--;
	}
}

bool zerocheck(int x, int y) {
	int cnt = 4;
	for (int i = 0; i < 4; i++) {
		int nx = x + dxdy[i][0];
		int ny = y + dxdy[i][1];
		if (nx<0 || nx>powN - 1 || ny<0 || ny>powN - 1) {
			cnt--; continue;
		}
		if (map[nx][ny] == 0) cnt--;
	}
	return cnt <= 2 ? true : false;
}

int bfs(int i, int j) {
	if (visit[i][j]) return 0;
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	visit[i][j] = true;
	int sum = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dxdy[k][0];
			int ny = y + dxdy[k][1];
			if (nx<0 || nx>powN - 1 || ny<0 || ny>powN - 1 || visit[nx][ny])continue;
			if (map[nx][ny] == 0)continue;
			q.push(make_pair(nx, ny));
			visit[nx][ny] = true;
			sum++;
		}
	}
	return sum;
}

int main() {
	cin >> n >> q;
	powN = pow(2, n);
	for (int i = 0; i < powN; i++) {
		for (int j = 0; j < powN; j++) {
			cin >> map[i][j];
		}
	}
	vector<pair<int, int>> v;
	while (q--) {
		int s;
		cin >> s;
		int size = pow(2, s);
		// 90도 회전
		for (int i = 0; i < powN; i += size) {
			for (int j = 0; j < powN; j += size) {
				//printf("rotate i = %d, j = %d, size = %d\n", i, j, size);
				rotate(i, j, size);
			}
		}
		// temp -> map
		for (int i = 0; i < powN; i++) {
			for (int j = 0; j < powN; j++) {
				map[i][j] = temp[i][j];
				temp[i][j] = 0;
			}
		}
		// 0 체크 후 얼음 녹이기
		for (int i = 0; i < powN; i++) {
			for (int j = 0; j < powN; j++) {
				if (map[i][j] > 0) {
					bool flag = zerocheck(i, j);
					if (flag) v.push_back(make_pair(i, j));
				}
			}
		}
		for (int i = 0; i < v.size(); i++) {
			map[v[i].first][v[i].second]--;
		}
		v.clear();
	}
	int ans = 0, maxland = 0;
	for (int i = 0; i < powN; i++) {
		for (int j = 0; j < powN; j++) {
			ans += map[i][j];
			if (map[i][j] > 0) {
				int land = bfs(i, j);
				if (maxland < land) maxland = land;
			}
		}
	}
	printf("%d\n%d\n", ans, maxland);
	return 0;
}