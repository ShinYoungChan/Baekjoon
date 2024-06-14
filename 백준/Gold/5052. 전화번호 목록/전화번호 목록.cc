#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> v;

int main() {
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		int n;
		cin >> n;
		v.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		bool flag = false;
		sort(v.begin(), v.end());
		for (int i = 0; i < n; i++) {
			if (flag) break;
			string str = v[i];
			for (int j = i + 1; j < n; j++) {
				// 같으면
				if (v[i] == v[j].substr(0, v[i].size())) {
					flag = true; break;
				}
				else break;
			}
		}
		if (flag) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
	}
	return 0;
}