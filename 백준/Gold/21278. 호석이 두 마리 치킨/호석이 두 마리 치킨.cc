#include <iostream>
#include <vector>
#include <algorithm>
#define INF 100000000

using namespace std;

void floydwarshall(vector<vector<int>>& v, int n) {
	// 자기 자신은 0
	for (int i = 0; i < n; i++) {
		v[i][i] = 0;
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (v[i][k] + v[k][j] < v[i][j]) {
					v[i][j] = v[i][k] + v[k][j];
				}
			}
		}
	}
}

void distCalc(vector<vector<int>> v, int n) {
	vector<bool> comb(n, false);
	for (int i = 0; i < 2; i++) {
		comb[i] = true;
	}
	int ans = INF;
	vector<int> dNum(2, INF);
	do {
		int dist = 0, idx = 0;
		vector<int> d(2);
		for (int i = 0; i < comb.size(); i++) {
			if (comb[i]) {
				d[idx++] = i;
			}
		}
		for (int i = 0; i < v.size(); i++) {
			int a = v[i][d[0]];
			int b = v[i][d[1]];
			dist += (a < b ? a * 2 : b * 2);
		}
		if (ans > dist) {
			ans = dist;
			dNum[0] = d[0];
			dNum[1] = d[1];
		}
	} while (prev_permutation(comb.begin(), comb.end()));

	printf("%d %d %d\n", dNum[0] + 1, dNum[1] + 1, ans);
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n, vector<int>(n, INF));

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a - 1][b - 1] = v[b - 1][a - 1] = 1;
	}

	floydwarshall(v, n);
	distCalc(v, n);

	return 0;
}