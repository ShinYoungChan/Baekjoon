#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	string str;
	vector<string> s;
	cin >> str;
	while (str.find('-') != string::npos) {
		string sub = str.substr(0, str.find('-'));
		s.push_back(sub);
		str = str.substr(str.find('-')+1);
	}
	s.push_back(str);
	int total = 0;
	for (unsigned int i = 0; i < s.size(); i++) {
		int sum = 0;
		while (s[i].find('+') != string::npos) {
			sum += stoi(s[i].substr(0, s[i].find('+')));
			s[i] = s[i].substr(s[i].find('+') + 1);
		}
		sum += stoi(s[i]);
		if (i == 0)
			total += sum;
		else
			total -= sum;
	}
	printf("%d\n", total);
	return 0;
}