#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	vector<int> aCnt(1000001, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	bool flag = false;
	int banner = (int)ceil(9 * m / 10.0);
	for (int i = 0; i < m; i++) {
		aCnt[v[i]]++;
		if (aCnt[v[i]] >= banner) {
			flag = true; break;
		}
	}

	for (int i = m; i < n; i++) {
		aCnt[v[i - m]]--; aCnt[v[i]]++;
		if (aCnt[v[i]] >= banner) {
			flag = true; break;
		}
	}
	if (flag)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}