#include <iostream>
#include <vector>

using namespace std;

class Robot {
public:
	int x, y, dir;
public:
	Robot() { x = y = dir = 0; }
};

int map[100][100];
int dxdy[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };	// 상 우 하 좌
int a, b, n, m, flag;
vector<Robot> v;

void Init() {
	cin >> b >> a;
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int x, y;
		char ch;
		cin >> y >> x >> ch;
		x = a - x;
		y = y - 1;
		v[i].x = x, v[i].y = y;
		map[x][y] = i;
		if (ch == 'N') v[i].dir = 0;
		else if (ch == 'E')v[i].dir = 1;
		else if (ch == 'S')v[i].dir = 2;
		else if (ch == 'W')v[i].dir = 3;
	}
}


void robotMove(int r, int cnt) {
	int x = v[r].x;
	int y = v[r].y;
	int dir = v[r].dir;
	map[x][y] = 0;
	for (int i = 0; i < cnt; i++) {
		x = x + dxdy[dir][0];
		y = y + dxdy[dir][1];
		// 로봇이 맵 밖을 벗어나는 경우
		if (x<0 || x>a - 1 || y<0 || y>b - 1) {
			printf("Robot %d crashes into the wall\n", r);
			flag = 1;
			return;
		}
		// 로봇과의 충돌이 발생하는 경우
		if (map[x][y] != 0) {
			printf("Robot %d crashes into robot %d\n", r, map[x][y]);
			flag = 1;
			return;
		}
	}
	v[r].x = x;
	v[r].y = y;
	map[x][y] = r;
}

void robotRotate(int r, char type, int cnt) {
	int dir = v[r].dir;
	if (type == 'R') {
		for (int i = 0; i < cnt; i++) {
			dir = (dir + 1) % 4;
		}
	}
	else {
		for (int i = 0; i < cnt; i++) {
			dir--;
			if (dir < 0) dir = 3;
		}
	}
	v[r].dir = dir;
}

int main() {
	Init();
	for (int i = 0; i < m; i++) {
		int r, cnt;
		char type;
		cin >> r >> type >> cnt;
		if (type == 'F') robotMove(r, cnt);
		else robotRotate(r, type, cnt);
		if (flag) break;
	}
	if (!flag) {
		printf("OK\n");
	}
	return 0;
}