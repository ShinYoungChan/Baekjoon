#include <iostream>
#include <vector>

using namespace std;

int dxdy[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };	// 동 서 남 북
bool visit[29][29];
int n;
double ans;
double per[4];

void dfs(int x, int y, int cnt, double val) {
	if (cnt == n) {
		ans += val;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dxdy[i][0];
		int ny = y + dxdy[i][1];

		if (!visit[nx][ny]) {
			visit[nx][ny] = true;
			dfs(nx, ny, cnt + 1, val * per[i]);
			visit[nx][ny] = false;
		}
	}
}

int main() {
	cin >> n;
	for(int i=0;i<4;i++){
		cin >> per[i];
		per[i] /= 100.0;
	}

	visit[14][14] = true;
	dfs(14, 14, 0, 1.0);
	printf("%.10f\n", ans);
	return 0;
}