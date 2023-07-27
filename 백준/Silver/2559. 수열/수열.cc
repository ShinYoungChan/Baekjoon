#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int sum = 0;
	for (int i = 0; i < k; i++) {
		sum += v[i];
	}
	int ans = sum;
	for (int i = k; i < n; i++) {
		sum = sum - v[i - k] + v[i];
		if (ans < sum)ans = sum;
	}
	printf("%d\n", ans);
	return 0;
}