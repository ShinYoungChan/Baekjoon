#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int sum = 0, mod2 = 0;
	for (int i = 0; i < n; i++) {
		int tree;
		cin >> tree;
		sum += tree;
		mod2 += tree / 2;
	}
	if (sum % 3 == 0 && mod2 >= sum / 3) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
	return 0;
}