#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, l;
	cin >> n >> l;
	
	vector<pair<int, int>> v(n);
	
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end());

	int ans = 0;
	int curr = 0;
	for (int i = 0; i < v.size(); i++) {
		// 이미 웅덩이가 덮힌 경우
		if (curr >= v[i].second)continue;
		// 현재위치가 웅덩이 시작 위치보다 작은 경우
		if (curr < v[i].first) {
			curr = v[i].first;
		}
		int cnt = (v[i].second - curr) / l;
		if ((v[i].second - curr) % l != 0) {
			cnt++;
		}
		ans += cnt;
		curr = curr + cnt * l;
	}
	printf("%d\n", ans);
	return 0;
}