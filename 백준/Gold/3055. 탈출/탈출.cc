#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int r, c, ex, ey, flag;
int dxdy[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
queue<tuple<int, int, int>> sq, wq;
vector<string> v;
vector<vector<bool>> visit;

void waterBfs(int time) {
	while (!wq.empty()) {
		auto [x, y, cnt] = wq.front();
		// 현재 시간에서 이미 다 움직였으면
		if (cnt > time) break;
		wq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dxdy[i][0];
			int ny = y + dxdy[i][1];
			if (nx<0 || nx>r - 1 || ny<0 || ny>c - 1)continue;
			// 이미 물로 차있거나 비버 굴이거나 돌이 있을때
			if (v[nx][ny] == '*' || v[nx][ny] == 'D' || v[nx][ny] == 'X')continue;
			v[nx][ny] = '*';
			wq.push(make_tuple(nx, ny, cnt + 1));
		}
	}
}

void beaverBfs(int time) {
	while (!sq.empty()) {
		auto [x, y, cnt] = sq.front();
		if (cnt > time)break;
		if (x == ex && y == ey) {
			flag = 1;
			break;
		}
		sq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dxdy[i][0];
			int ny = y + dxdy[i][1];
			if (nx<0 || nx>r - 1 || ny<0 || ny>c - 1 || visit[nx][ny])continue;
			// 물로 차있거나 돌이 있을때
			if (v[nx][ny] == '*' || v[nx][ny] == 'X')continue;
			visit[nx][ny] = true;
			sq.push(make_tuple(nx, ny, cnt + 1));

		}
	}
}

int main() {
	cin >> r >> c;
	v.resize(r);
	visit.resize(r);
	for (int i = 0; i < r; i++) {
		cin >> v[i];
		visit[i].resize(c);
		for (int j = 0; j < c; j++) {
			visit[i][j] = false;
			if (v[i][j] == '*') {
				wq.push(make_tuple(i, j, 0));
			}
			if (v[i][j] == 'S') {
				sq.push(make_tuple(i, j, 0));
				visit[i][j] = true;
			}
			if (v[i][j] == 'D') {
				ex = i, ey = j;
			}
		}
	}
	int time = 0;
	while (true) {
		waterBfs(time);
		beaverBfs(time);
		// 탈출했거나 더 이상 움직이지 못할때
		if (flag || sq.empty()) break;
		time++;
	}
	if (flag) {
		printf("%d\n", time);
	}
	else {
		printf("KAKTUS\n");
	}
	return 0;
}