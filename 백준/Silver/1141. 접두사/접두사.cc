#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
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
	unordered_set<string> str;
	for (int i = 0; i < v.size(); i++) {
		bool flag = true;
		for (int j = i + 1; j < v.size(); j++) {
			int n = v[j].find(v[i]);
			if (n == 0) {
				flag = false; break;
			}
			else break;
		}
		if (flag) str.insert(v[i]);
	}
	printf("%d\n", str.size());
	return 0;
}