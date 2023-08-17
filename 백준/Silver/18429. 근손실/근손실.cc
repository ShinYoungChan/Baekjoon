#include <iostream>
#include <vector>

using namespace std;

int n, k, ans;
vector<int> v;
vector<bool> visit;

void dfs(int w, int cnt) {
	if (w < 500)return;
	if (cnt == n) {
		if (w >= 500)ans++;
	}
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			dfs(w + v[i] - k, cnt + 1);
			visit[i] = false;
		}
	}
}

int main() {
	cin >> n >> k;
	v.resize(n); visit.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			dfs(500 + v[i] - k, 1);
			visit[i] = false;
		}
	}
	printf("%d\n", ans);
	return 0;
}