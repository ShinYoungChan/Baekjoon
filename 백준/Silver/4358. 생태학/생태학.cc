#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<string, int> tree;
	string s;
	int count = 0;
	while (getline(cin, s)) {
		if (s == "")
			break;
		tree[s] += 1;
		count++;
	}
	for (auto t : tree) {
		printf("%s %.4f\n", t.first.c_str(), (t.second / (float)count) * 100);
	}
	return 0;
}