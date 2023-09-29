#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<int> ans(n, 1);
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (v[i] < v[j]) {
				ans[j] = max(ans[i] + 1, ans[j]);
			}
		}
	}
	printf("%d\n", *max_element(ans.begin(), ans.end()));
	return 0;
}