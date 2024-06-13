#include <iostream>
#include <string>

using namespace std;

int main() {
	string str1, str2;
	cin >> str1 >> str2;
	
	int ans = 51;
	int len1 = str1.size();
	int len2 = str2.size();

	for (int i = 0; i < len2 - len1 + 1; i++) {
		int cnt = 0;
		for (int j = 0; j < len1; j++) {
			if (str1[j] != str2[j+i]) cnt++;
		}
		if (ans > cnt)ans = cnt;
	}
	printf("%d\n", ans);
}