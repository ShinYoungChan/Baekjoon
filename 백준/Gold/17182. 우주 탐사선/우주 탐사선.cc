#include <iostream>

using namespace std;

int map[10][10];
bool visit[10];
int N, K;
int ans = 2100000000;

void floyd() {
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][k] + map[k][j] < map[i][j])
					map[i][j] = map[i][k] + map[k][j];
			}
		}
	}
}

void dfs(int idx, int sum, int cnt) {
	if (cnt == N) {
		if (ans > sum) ans = sum;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			dfs(i, sum + map[idx][i], cnt + 1);
			visit[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	floyd();
	visit[K] = true;
	dfs(K, 0, 1);
	cout << ans << "\n";
	return 0;
}