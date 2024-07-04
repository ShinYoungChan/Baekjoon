#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, l;
	cin >> n >> l;
	
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int s = v[0], ans = 1;
	for (int i = 1; i < n; i++) {
		if (v[i] - s + 1 > l) {
			ans++;
			s = v[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}