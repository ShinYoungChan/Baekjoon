#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		bool flag = true;
		for (int j = i + 1; j < v.size(); j++) {
			int n = v[j].find(v[i]);
			if (n == 0) {
				flag = false; break;
			}
			else break;
		}
		if (flag) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}