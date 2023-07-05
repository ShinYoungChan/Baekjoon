#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k, b;
	cin >> n >> k >> b;
	vector<int> v(n, 0);
	for (int i = 0; i < b; i++) {
		int num;
		cin >> num;
		v[num - 1] = 1;
	}
	int ans = n;
	int sum = 0;
	for (int i = 0; i < k; i++) {
		sum += v[i];
	}
	if (ans > sum) ans = sum;
	for (int i = k; i < n; i++) {
		sum = sum - v[i - k] + v[i];
		if (ans > sum) ans = sum;
	}
	printf("%d\n", ans);
	return 0;
}