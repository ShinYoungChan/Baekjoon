#include <iostream>
#include <vector>

using namespace std;

class Fire {
public:
	int r, c, m, s, d;
public:
	Fire() {
		r = c = m = s = d = 0;
	}
	Fire(int _r, int _c, int _m, int _s, int _d) {
		r = _r, c = _c, m = _m, s = _s, d = _d;
	}
};

int n, m, k;
vector<Fire> fireMap[50][50];
int mMap[50][50], sMap[50][50], dMap[50][50], sCnt[50][50];
int dxdy[8][2] = { {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };

void move(Fire fire) {
	int nx = (fire.r + dxdy[fire.d][0] * fire.s) % n;
	int ny = (fire.c + dxdy[fire.d][1] * fire.s) % n;
	if (nx < 0)nx += n;
	if (ny < 0)ny += n;


	mMap[nx][ny] += fire.m;
	sMap[nx][ny] += fire.s;
	sCnt[nx][ny]++;
	if (dMap[nx][ny] == 1000) {
		dMap[nx][ny] = fire.d;
	}
	// 값 들어온 경우
	else if (dMap[nx][ny] >= 0) {
		if ((dMap[nx][ny] & 1) != (fire.d & 1)) {
			dMap[nx][ny] = -1;
		}
	}

}

void division(int x, int y) {
	//copydMap = - 1 이면 1 3 5 7 아니면 0 2 4 6
	int dir = 0;
	if (dMap[x][y] == -1)dir = 1;
	// 파이어볼 나누기 질량은(질량 합 / 5), 속력은(속력 합 / 파이어볼 개수), 방향은 모두 홀수 또는 모두 짝수면 0, 2, 4, 6 아니면 1, 3, 5, 7, 질량 0 파이어볼 소멸
	int divM = mMap[x][y] / 5;
	int divS = sMap[x][y] / sCnt[x][y];
	if (divM == 0)return;
	for (; dir < 8; dir += 2) {
		fireMap[x][y].push_back(Fire(x, y, divM, divS, dir));
	}
}

void reset() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mMap[i][j] = sMap[i][j] = sCnt[i][j] = 0;
			dMap[i][j] = 1000;
		}
	}
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		fireMap[r - 1][c - 1].push_back(Fire(r - 1, c - 1, m, s, d));
	}
	while (k--) {
		reset();
		// 파이어볼 이동 및 합치기
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int f = 0; f < fireMap[i][j].size(); f++) {
					move(fireMap[i][j][f]);
				}
				fireMap[i][j].clear();
			}
		}
		// 파이어볼 나누기 질량은 (질량 합 / 5), 속력은 (속력 합 / 파이어볼 개수), 방향은 모두 홀수 또는 모두 짝수면 0,2,4,6 아니면 1,3,5,7, 질량 0 파이어볼 소멸
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (sCnt[i][j] == 1) {
					fireMap[i][j].push_back(Fire(i, j, mMap[i][j], sMap[i][j], dMap[i][j]));
				}
				else if (sCnt[i][j] > 1) {
					division(i, j);
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int f = 0; f < fireMap[i][j].size(); f++) {
				ans += fireMap[i][j][f].m;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}