#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	map<string, int> out;
	map<string, int> result;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		out[s] += 1;
	}
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (out.count(s) == 1)
			result[s] += 1;
	}
	printf("%d\n", result.size());
	for (auto r : result)
		printf("%s\n", r.first.c_str());
	return 0;
}