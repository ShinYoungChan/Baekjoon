#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<string> map(8);
vector<pair<int, int>> wookje, wall;
bool flag = false;
int dxdy[9][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1} };

void move() {
	queue<pair<int, int>> q;
	for (int i = 0; i < wookje.size(); i++) {
		if (map[wookje[i].first][wookje[i].second] == '#')continue;
		q.push(make_pair(wookje[i].first, wookje[i].second));
	}
	wookje.clear();
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 9; i++) {
			int mx = x + dxdy[i][0];
			int my = y + dxdy[i][1];
			if (mx < 0 || mx>7 || my < 0 || my>7 || map[mx][my] == '#')continue;
			if (mx == 0 && my == 7) {
				flag = true; break;
			}
			wookje.push_back(make_pair(mx, my));
		}
	}
}

void down() {
	queue<pair<int, int>> q;
	for (int i = 0; i < wall.size(); i++) {
		map[wall[i].first][wall[i].second] = '.';
		q.push(make_pair(wall[i].first, wall[i].second));
	}
	wall.clear();
	while (!q.empty()) {
		int x = q.front().first + 1;
		int y = q.front().second;
		q.pop();
		if (x > 7)continue;
		map[x][y] = '#';
		wall.push_back(make_pair(x, y));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 8; i++) {
		cin >> map[i];
		for (int j = 0; j < 8; j++) {
			if (map[i][j] == '#')
				wall.push_back(make_pair(i, j));
		}
	}
	wookje.push_back(make_pair(7, 0));
	while (true) {
		move();
		down();
		if (flag)break;
		if (wookje.size() == 0)break;
	}
	printf("%d\n", flag == true ? 1 : 0);
	return 0;
}