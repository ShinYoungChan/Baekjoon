#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct info {
	int rx, ry, bx, by, cnt;
};

vector<string> map;
info start;
bool visited[10][10][10][10];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

int bfs() {
	queue<info> q;
	q.push(start);
	start.cnt = 0;
	visited[start.rx][start.ry][start.bx][start.by] = true;
	int ret = -1;
	while (!q.empty()) {
		info cur = q.front();
		q.pop();
		if (cur.cnt > 10)break;
		if (map[cur.rx][cur.ry] == 'O' && map[cur.bx][cur.by] != 'O') {
			ret = cur.cnt; break;
		}
		for (int dir = 0; dir < 4; dir++) {
			int next_rx = cur.rx;
			int next_ry = cur.ry;
			int next_bx = cur.bx;
			int next_by = cur.by;
			while (true) {
				if (map[next_rx][next_ry] != '#' && map[next_rx][next_ry] != 'O') {
					next_rx += dx[dir];
					next_ry += dy[dir];
				}
				else {
					if (map[next_rx][next_ry] == '#') {
						next_rx -= dx[dir];
						next_ry -= dy[dir];
					}
					break;
				}
			}
			while (true) {
				if (map[next_bx][next_by] != '#' && map[next_bx][next_by] != 'O') {
					next_bx += dx[dir];
					next_by += dy[dir];
				}
				else {
					if (map[next_bx][next_by] == '#') {
						next_bx -= dx[dir];
						next_by -= dy[dir];
					}
					break;
				}
			}
			if (next_rx == next_bx && next_ry == next_by) {
				if (map[next_rx][next_ry] != 'O') {
					int rDist = abs(next_rx - cur.rx) + abs(next_ry - cur.ry);
					int bDist = abs(next_bx - cur.bx) + abs(next_by - cur.by);
					if (rDist > bDist) {
						next_rx -= dx[dir];
						next_ry -= dy[dir];
					}
					else {
						next_bx -= dx[dir];
						next_by -= dy[dir];
					}
				}
			}
			if (!visited[next_rx][next_ry][next_bx][next_by]) {
				info next;
				next.rx = next_rx;
				next.ry = next_ry;
				next.bx = next_bx;
				next.by = next_by;
				next.cnt = cur.cnt + 1;
				q.push(next);
			}
		}
	}
	return ret;
}


int main() {
	int n, m;
	cin >> n >> m;
	map.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> map[i];
		for (int j = 0; j < map[i].size(); j++) {
			if (map[i][j] == 'R') {
				start.rx = i;
				start.ry = j;
			}
			if (map[i][j] == 'B') {
				start.bx = i;
				start.by = j;
			}
		}
	}
	int answer = bfs();
	cout << answer << "\n";
	return 0;
}