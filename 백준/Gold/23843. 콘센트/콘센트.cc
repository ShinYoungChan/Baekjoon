#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;
	vector<int> v(n), power(m);
	
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), greater<>());

	for (int i = 0; i < n; i++) {
		int idx = -1, flag = 0, w = INT32_MAX;	// 제일 낮은 값을 가지는 인덱스, 작업 여부, 제일 낮은 시간값
		for (int j = 0; j < m; j++) {
			// 현재 작업 목록이 없으면 바로 power에 삽입
			if (power[j]==0) {
				power[j] = v[i]; flag = 1;
				break;
			}
			// 현재 작업시간이 작은 경우
			if (w >= power[j]) {
				w = power[j];
				idx = j;
			}
		}
		if (!flag) {
			power[idx] += v[i];
		}
	}
	int ans = 0;

	for (int i = 0; i < m; i++) {
		if (ans < power[i]) ans = power[i];
	}

	printf("%d\n", ans);
	return 0;
}