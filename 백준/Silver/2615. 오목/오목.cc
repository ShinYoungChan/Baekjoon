#include <iostream>

using namespace std;

int map[19][19];
int dxdy[4][2] = { {0,1},{1,0},{1,1},{-1,1} };

bool checkGo(int ox, int oy, int baduk) {
	for (int i = 0; i < 4; i++) {
		int cnt = 0;
		int x = ox, y = oy;
		while (x >= 0 && x < 19 && y >= 0 && y < 19 && map[x][y] == baduk) {
			cnt++;
			x += dxdy[i][0];
			y += dxdy[i][1];
		}
		x = ox - dxdy[i][0];
		y = oy - dxdy[i][1];
		if (cnt == 5) {
			if (x >= 0 && x < 19 && y >= 0 && y < 19 && map[x][y] == baduk) {
				return false;
			}
			return true;
		}
	}
	return false;
}

int main() {
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			cin >> map[i][j];
		}
	}

	bool bflag = false, wflag = false;
	int x = 0, y = 0;
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (map[i][j] == 1 && checkGo(i, j, 1)) {
				bflag = true;
				x = i, y = j;
				break;
			}
			if (map[i][j] == 2 && checkGo(i, j, 2)) {
				wflag = true;
				x = i, y = j;
				break;
			}
		}
		if (bflag || wflag) break;
	}
	if (bflag) {
		printf("1\n%d %d\n", x + 1, y + 1);
	}
	else if (wflag) {
		printf("2\n%d %d\n", x + 1, y + 1);
	}
	else {
		printf("0\n");
	}
	return 0;
}