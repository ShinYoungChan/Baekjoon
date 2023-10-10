#include <iostream>
#include <vector>

using namespace std;

int n;

int binary_search(int target, vector<int>& ans) {
	int start = 0, end = ans.size() - 1, mid;
	while (start < end) {
		mid = (start + end) / 2;
		if (ans[mid] >= target) end = mid;
		else start = mid + 1;
	}
	return end;
}

int main() {
	while (cin >> n) {
		vector<int> v(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		vector<int> ans;
		for (int i = 0; i < n; i++) {
			if (ans.size() == 0) ans.push_back(v[i]);
			if (ans.back() < v[i]) ans.push_back(v[i]);
			else {
				int idx = binary_search(v[i], ans);
				ans[idx] = v[i];
			}
		}
		printf("%d\n", ans.size());
	}
	return 0;
}