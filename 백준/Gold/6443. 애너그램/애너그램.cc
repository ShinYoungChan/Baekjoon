#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	int test;
	scanf("%d", &test);
	while (test--) {
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		do {
			for (int i = 0; i < s.size(); i++)
				printf("%c", s[i]);
			printf("\n");
		} while (next_permutation(s.begin(), s.end()));
	}
	return 0;
}