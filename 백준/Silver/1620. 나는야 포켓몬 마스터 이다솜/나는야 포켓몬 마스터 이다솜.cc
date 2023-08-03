#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<string> v(n);
	map<string, int> map;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		map[v[i]] = i + 1;
	}
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		if (isdigit(str[0])) {
			printf("%s\n", v[stoi(str) - 1].c_str());
		}
		else {
			printf("%d\n", map[str]);
		}
	}
	return 0;
}