#include <iostream>
#include <vector>

using namespace std;

const int INF = 100000001;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n + 1, vector<int>(n + 1, INF));

	for (int i = 0; i < m; i++) {
		int n1, n2, cost;
		cin >> n1 >> n2 >> cost;
		v[n1][n2] = min(v[n1][n2], cost);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j)v[i][j] = 0;
				else v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", v[i][j] == INF ? 0 : v[i][j]);
		}
		printf("\n");
	}
	return 0;
}