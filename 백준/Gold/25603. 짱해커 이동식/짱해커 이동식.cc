#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int request = 2100000000, mIdx = 0;
	for (int i = 0; i < k; i++) {
		if (request >= v[i]) {
			request = v[i]; mIdx = i + 1;
		}
	}
	int ans = request;
	while (mIdx + k <= n) {
		int re = 2100000000, idx = 0;
		for (int i = mIdx; i < mIdx + k; i++) {
			if (re >= v[i]) {
				re = v[i]; idx = i + 1;
			}
		}
		mIdx = idx;
		if (ans < re) ans = re;
	}
	printf("%d\n", ans);
	return 0;
}