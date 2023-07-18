#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
		sum += v[i].second;
	}
	sort(v.begin(), v.end());
	long long cur = 0;
	for (int i = 0; i < n; i++) {
		cur += v[i].second;
		if (cur >= (sum+1) / 2) {
			printf("%d\n", v[i].first);
			break;
		}
	}
	return 0;
}