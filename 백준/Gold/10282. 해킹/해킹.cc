#include <iostream>
#include <vector>
#include <queue>
#define INF 2100000000

using namespace std;

vector<vector<pair<int,int>>> v;

void bfs(int n, int c) {
	priority_queue<pair<int, int>> pq;
	vector<bool> visit(n + 1, false);
	vector<int> dist(n + 1, INF);
	visit[c] = true;
	dist[c] = 0;
	pq.push(make_pair(0, c));
	while (!pq.empty()) {
		int d = -pq.top().first;
		int curr = pq.top().second;
		pq.pop();
		if (dist[curr] > d)continue;
		for (auto a : v[curr]) {
			int next = a.first;
			int nd = a.second;
			if (dist[next] > d + nd) {
				dist[next] = d + nd;
				pq.push(make_pair(-dist[next], next));
			}
		}
	}
	int max = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (dist[i] != INF) {
			cnt++;
			if (dist[i] > max) max = dist[i];
		}
	}
	printf("%d %d\n", cnt, max);
}

int main() {
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		int n, d, c;
		cin >> n >> d >> c;
		v.clear();
		v.resize(n + 1);
		for (int i = 0; i < d; i++) {
			int a, b, s;
			cin >> a >> b >> s;
			//v[a].push_back(make_pair(b, s));
			v[b].push_back(make_pair(a, s));
		}
		bfs(n, c);
	}
	return 0;
}