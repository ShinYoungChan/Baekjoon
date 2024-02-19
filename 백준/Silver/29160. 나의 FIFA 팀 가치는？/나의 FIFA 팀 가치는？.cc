#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<priority_queue<int>> pq(12);

void decrease() {
	for (int i = 1; i < 12; i++) {
		if (pq[i].size() > 0 && pq[i].top() > 0) {
			int num = pq[i].top() - 1;
			pq[i].pop();
			pq[i].push(num);
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int p, w;
		cin >> p >> w;
		pq[p].push(w);
	}
	for (int i = 0; i < k; i++) {
		decrease();
	}
	
	int ans = 0;
	for (int i = 1; i < 12; i++) {
		if (pq[i].size() > 0) {
			ans += pq[i].top();
		}
	}
	printf("%d\n", ans);
	return 0;
}