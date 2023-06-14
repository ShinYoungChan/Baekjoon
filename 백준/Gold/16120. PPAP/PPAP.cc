#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	string str;
	cin >> str;
	stack<char> s;
	bool flag = true;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'P') {
			s.push(str[i]);
		}
		else {
			if (s.size() < 2 || str[i+1]!='P') {
				flag = false; break;
			}
			s.pop(); s.pop();
			s.push('P'); i++;
		}
	}
	if (s.size() > 1) flag = false;
	printf("%s\n", flag ? "PPAP" : "NP");
	return 0;
}