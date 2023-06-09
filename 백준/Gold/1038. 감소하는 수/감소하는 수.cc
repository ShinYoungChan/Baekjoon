#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> v;

void dfs(long long num) {
	if (num > 1000000000)return;
	int start = num % 10;
	for (int i = start - 1; i >= 0; i--) {
		v.push_back(num * 10 + i);
		dfs(num * 10 + i);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
		dfs(i);
	}
	sort(v.begin(), v.end());
	if (v.size() <= n)
		printf("-1\n");
	else
		printf("%lld\n", v[n]);
	return 0;
}