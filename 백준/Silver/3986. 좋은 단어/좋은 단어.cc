#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);
	int count = 0;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		stack<char> ch;
		for (int j = 0; j < str.length(); j++) {
			if (ch.empty()) {
				ch.push(str[j]);
				continue;
			}
			if (ch.top() == str[j])
				ch.pop();
			else
				ch.push(str[j]);
		}
		if (ch.size() == 0)
			count++;
	}
	printf("%d\n", count);
	return 0;
}