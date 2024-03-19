#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int,int>>> v;
vector<bool> visit;
int ans = 0;
int child = 0;

void dfs(int p, int sum) {
	if (ans < sum) {
		ans = sum;
		child = p;
	}
	for (int i = 0; i < v[p].size(); i++) {
		if (!visit[v[p][i].first]) {
			visit[v[p][i].first] = true;
			dfs(v[p][i].first, sum + v[p][i].second);
		}
	}
}

int main() {
	int n;
	cin >> n;
	v.resize(n + 1);
	visit.resize(n + 1, false);
	for (int i = 0; i < n - 1; i++) {
		int n1, n2, w;
		cin >> n1 >> n2 >> w;
		v[n1].push_back(make_pair(n2, w));
		v[n2].push_back(make_pair(n1, w));
	}
	visit[1] = true;
	dfs(1, 0);

	ans = 0;
	visit.assign(n + 1, false);
	visit[child] = true;
	dfs(child, 0);

	printf("%d\n", ans);
}