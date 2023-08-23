#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	string str;
	char ch[5] = { 'a','e','i','o','u' };
	while (cin>>str) {
		if (str == "end")
			break;
		bool check = true;
		for (int i = 0; i < 5; i++) {
			string s;
			s += ch[i];
			if (str.find(s) != string::npos) {
				check = true;
				break;
			}
			else
				check = false;
		}
		int gather = 0;
		int consonant = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
				gather++;
				consonant = 0;
			}
			else {
				gather = 0;
				consonant++;
			}
			if (gather >= 3 || consonant >= 3) {
				check = false;
				break;
			}
		}
		for (char i = 'a'; i <= 'z'; i++) {
			if (i == 'e' || i == 'o')
				continue;
			string s;
			for (int j = 0; j < 2; j++)
				s += i;
			if (str.find(s) != string::npos) {
				check = false;
				break;
			}
		}
		if (check)
			printf("<%s> is acceptable.\n", str.c_str());
		else
			printf("<%s> is not acceptable.\n", str.c_str());
	}
	return 0;
}