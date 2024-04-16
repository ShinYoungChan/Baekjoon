#include <iostream>
#include <unordered_set>

using namespace std;

int map[10][10];
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

void dfs(unordered_set<int> us, int sum, int idx) {
	if (us.size() == N) {
		if (ans > sum) ans = sum;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (us.count(i) == 0) {
			us.insert(i);
			dfs(us, sum + map[idx][i], i);
			us.erase(i);
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
	unordered_set<int> us;
	us.insert(K);
	floyd();
	dfs(us, 0, K);
	cout << ans << "\n";
	return 0;
}