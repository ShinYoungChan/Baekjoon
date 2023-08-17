#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, s;
	cin >> n >> s;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		vector<bool> comb(n);
		for (int j = n - i; j < n; j++) {
			comb[j] = true;
		}
		do {
			int sum = 0;
			for (int j = 0; j < v.size(); j++) {
				if (comb[j]) {
					sum += v[j];
				}
			}
			if (sum == s)ans++;
		} while (next_permutation(comb.begin(), comb.end()));
	}
	printf("%d\n", ans);
	return 0;
}