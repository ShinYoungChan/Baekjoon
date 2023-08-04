#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 2100000000;

vector<vector<pair<int, int>>> v;

void bfs(int start, vector<int>& dist) {
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	dist[start] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int curr = pq.top().second;
		pq.pop();
		if (dist[curr] < cost)continue;
		for (auto next : v[curr]) {
			int nDist = dist[curr] + next.second;
			if (dist[next.first] > nDist) {
				dist[next.first] = nDist;
				pq.push(make_pair(-nDist, next.first));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int n1, n2, cost;
		cin >> n1 >> n2 >> cost;
		v[n1].push_back(make_pair(n2, cost));
	}
	int start, end;
	cin >> start >> end;
	vector<int> dist(n + 1, INF);
	bfs(start, dist);
	printf("%d\n", dist[end]);
	return 0;
}