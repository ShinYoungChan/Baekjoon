#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cin >> m;
	vector<int> w(m, 0);
	for (int i = 0; i < m; i++) {
		cin >> w[i];
	}
	sort(v.begin(), v.end(), greater<int>());
	sort(w.begin(), w.end(), greater<int>());
	int time = -1;
	bool flag = true;
	while (flag) {
		flag = false;
		for (int i = 0; i < n; i++) {
			for (auto it = w.begin(); it != w.end();) {
				if (v[i] >= *it) {
					flag = true;
					it = w.erase(it);
					break;
				}
				else {
					it++;
				}
			}
		}
		time++;
	}
	if (w.size() > 0)
		time = -1;
	printf("%d\n", time);
	return 0;
}