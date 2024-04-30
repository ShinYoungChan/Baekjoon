#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n), bee(n), backbee(n);
	int asd = 0, idx = -1;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		backbee[i] = bee[i] = v[i];
		if (asd < v[i]) {
			asd = v[i];
			idx = i;
		}
	}
	for (int i = 1; i < n; i++) {
		bee[i] = bee[i] + bee[i - 1];
	}
	for (int i = v.size() - 2; i >= 0; i--) {
		backbee[i] = backbee[i] + backbee[i + 1];
	}
	int max = 0;
	for (int i = 1; i < v.size() - 1; i++) {
		// 처음 출발 하는 벌 + 두번째 출발하는 벌
		int sum = (bee[v.size() - 1] - v[i] - v[0]) + (bee[v.size() - 1] - bee[i - 1] - v[i]);
		if (max < sum) max = sum;
	}
	for (int i = v.size() - 2; i > 0; i--) {
		int sum = (backbee[0] - v[i] - v[v.size() - 1]) + (backbee[0] - backbee[i + 1] - v[i]);
		if (max < sum)max = sum;
	}
	int sum = 0;
	for (int i = 1; i <= idx; i++) {
		sum += v[i];
	}
	for (int i = v.size() - 2; i >= idx; i--) {
		sum += v[i];
	}
	if (max < sum)max = sum;
	printf("%d\n", max);
	return 0;
}