#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(3, 0), maxDp(3, 0), minDp(3, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[0] >> v[1] >> v[2];
		int temp1 = maxDp[0], temp2 = maxDp[2];
		maxDp[0] = max(maxDp[0], maxDp[1]) + v[0];
		maxDp[2] = max(maxDp[1], maxDp[2]) + v[2];
		maxDp[1] = max(max(temp1, maxDp[1]), temp2) + v[1];

		temp1 = minDp[0], temp2 = minDp[2];
		minDp[0] = min(minDp[0], minDp[1]) + v[0];
		minDp[2] = min(minDp[1], minDp[2]) + v[2];
		minDp[1] = min(min(temp1, minDp[1]), temp2) + v[1];
	}
	int minNum = min(min(minDp[0], minDp[1]), minDp[2]);
	int maxNum = max(max(maxDp[0], maxDp[1]), maxDp[2]);
	printf("%d %d\n", maxNum, minNum);
	return 0;
}