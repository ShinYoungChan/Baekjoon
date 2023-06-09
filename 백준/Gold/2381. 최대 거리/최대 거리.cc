#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	vector<int> plus;
	vector<int> minus;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		plus.push_back(n1 + n2);
		minus.push_back(n1 - n2);
	}
	sort(plus.begin(), plus.end());
	sort(minus.begin(), minus.end());
	printf("%d\n", max(plus[plus.size() - 1] - plus[0], minus[minus.size() - 1] - minus[0]));
	return 0;
}