#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), greater<int>());

	long long sum = 0;
	for (int i = 0; i < v.size(); i++) {
		int tip = v[i] - (i + 1 - 1);
		if (tip > 0)
			sum += tip;
	}
	printf("%lld\n", sum);
	return 0;
}