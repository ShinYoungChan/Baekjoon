#include <iostream>

using namespace std;

int main() {
	int n, ans = 0;
	cin >> n;
	if (n >= 5) {
		ans += n / 5;
		n %= 5;
		if (n & 1) {
			n += 5;
			ans--;
		}
	}
	if (n >= 2) {
		ans += n / 2;
		n %= 2;
	}
	if (n > 0)ans = -1;
	printf("%d\n", ans);
	return 0;
}