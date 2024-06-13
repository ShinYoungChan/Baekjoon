#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class word {
public:
	string name;
	int cnt;
	int size;
public:
	word(string _name, int _cnt, int _size) {
		name = _name; cnt = _cnt; size = _size;
	}
};

bool cmp(word &a, word &b) {
	//정렬순서: 자주 나온 순 -> 단어 길이 -> 사전 순
	if (a.cnt == b.cnt) {
		if (a.size == b.size) {
			return a.name < b.name;
		}
		return a.size > b.size;
	}
	return a.cnt > b.cnt;
}

unordered_map<string, int> um;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		um[str]++;
	}

	vector<word> v;
	for (auto m : um) {
		v.push_back(word(m.first, m.second, m.first.size()));
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		if (v[i].size >= m) {
			printf("%s\n", v[i].name.c_str());
		}
	}
	return 0;
}