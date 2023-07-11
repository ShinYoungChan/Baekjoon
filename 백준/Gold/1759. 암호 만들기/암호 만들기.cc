#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int l, c;
vector<char> v;
vector<string> ans;

void dfs(int idx, string str, int cnt1, int cnt2) {
	if (str.size() == l) {
		if (cnt1 >= 1 && cnt2 >= 2) ans.push_back(str);
		return;
	}
	for (int i = idx + 1; i < c; i++) {
		if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u')
			dfs(i, str + v[i], cnt1 + 1, cnt2);
		else
			dfs(i, str + v[i], cnt1, cnt2 + 1);
	}
}

int main() {
	cin >> l >> c;
	v.resize(c);
	for (int i = 0; i < c; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i <= c - l; i++) {
		string str;
		str += v[i];
		if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u')
			dfs(i, str, 1, 0);
		else
			dfs(i, str, 0, 1);
	}
	for (auto s : ans) {
		printf("%s\n", s.c_str());
	}
	return 0;
}