#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main() {
	int n;
	cin >> n;
	stack<pair<string, int>> s;
	for (int i = 0; i < n; i++) {
		string str, ch;
		int num;
		cin >> str >> ch >> num;
		s.push(make_pair(ch, num));
	}
	string ans = "";
	while (!s.empty()) {
		string str = s.top().first;
		int time = s.top().second;
		s.pop();
		if (str[0] >= 'a' && str[0] <= 'z') {
			ans += str;
		}
		else {
			int ctime = stoi(str);
			int diff = time - ctime;
			while (!s.empty() && diff <= s.top().second) {
				s.pop();
			}
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		printf("%c", ans[i]);
	}
	printf("\n");
	return 0;
}