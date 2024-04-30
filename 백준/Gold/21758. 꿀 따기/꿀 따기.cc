#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n), bee(n), backbee(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		backbee[i] = bee[i] = v[i];
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
	// 꿀통 위치
	for (int i = 1; i < v.size() - 1; i++) {
		int sum = 0;
		for (int j = 1; j <= i; j++) {
			sum += v[j];
		}
		for (int j = v.size() - 2; j >= i; j--) {
			sum += v[j];
		}
		if (max < sum)max = sum;
	}
	printf("%d\n", max);
	return 0;
}