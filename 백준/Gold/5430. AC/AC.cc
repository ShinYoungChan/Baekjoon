#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test;
	cin >> test;
	while (test--) {
		string command, arr;
		deque<int> v;
		int n;
		cin >> command;
		cin >> n;
		cin >> arr;
		int num = 0;
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] >= 48 && arr[i] <= 57) {
				num = num * 10 + arr[i] - 48;
			}
			else {
				if (num != 0) {
					v.push_back(num);
					num = 0;
				}
			}
		}
		bool check = true;
		int rflag = 0;
		for (int i = 0; i < command.size(); i++) {
			if (command[i] == 'R') {
				rflag = (++rflag) % 2;
			}
			else {
				if (v.size() == 0) {
					check = false;
					break;
				}
				if (rflag == 1)
					v.pop_back();
				else
					v.pop_front();
			}
		}
		if (check) {
			string newstr = "[";
			if (rflag)
				reverse(v.begin(), v.end());
			for (int i = 0; i < v.size(); i++) {
				newstr += to_string(v[i]);
				newstr += ",";
			}
			if (newstr[newstr.size() - 1] == ',')
				newstr.pop_back();
			newstr += "]";
			printf("%s\n", newstr.c_str());
		}
		else
			printf("error\n");
	}
	return 0;
}