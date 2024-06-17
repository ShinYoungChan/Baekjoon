#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> v(n);
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < m; i++) {
		pq.push(0);
	}

	sort(v.begin(), v.end(), greater<int>());

	for (int i = 0; i < n; i++) {
		int x = pq.top() + v[i];
		pq.pop();
		pq.push(x);
	}

	int ans = 0;
	while (!pq.empty()) {
		ans = pq.top();
		pq.pop();
	}
	printf("%d\n", ans);
	return 0;
}