#include <iostream>

using namespace std;

int main() {
	int e, s, m;
	cin >> e >> s >> m;
	int year = 0, ee = 0, ss = 0, mm = 0;
	while (true) {
		year++;
		ee = (ee+1) % 15;
		ss = (ss+1) % 28;
		mm = (mm+1) % 19;
		if (ee == 0)ee = 15;
		if (ss == 0)ss = 28;
		if (mm == 0)mm = 19;
		if (e == ee && s == ss && m == mm)break;
	}
	printf("%d\n", year);
	return 0;
}