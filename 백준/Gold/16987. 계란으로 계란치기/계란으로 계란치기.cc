#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v;
int n, ans;

void dfs(int idx) {
	if (idx == n) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (v[i].first <= 0)cnt++;
		}
		if (ans < cnt)ans = cnt;
		return;
	}

	if (v[idx].first <= 0) {
		dfs(idx + 1);
		return;
	}
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (idx == i)continue;
		if (v[i].first > 0) {
			v[idx].first -= v[i].second;
			v[i].first -= v[idx].second;
			flag = true;
			dfs(idx + 1);
			v[idx].first += v[i].second;
			v[i].first += v[idx].second;
		}
	}
	if (!flag) dfs(n);
}

int main() {
	cin >> n;
	v.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	dfs(0);

	printf("%d\n", ans);
	return 0;
}