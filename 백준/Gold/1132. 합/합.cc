#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<ll> chNum(10, 0);
	vector<bool> alpha(10, false);
	for (int i = 0; i < v.size(); i++) {
		ll mul = 1;
		//첫번째 자리 알파벳 체크
		alpha[v[i][0] - 'A'] = true;
		for (int j = v[i].size() - 1; j >= 0; j--) {
			chNum[v[i][j] - 'A'] += mul;
			mul *= 10;
		}
	}
	bool flag = false;
	for (int i = 0; i < 10; i++) {
		//첫번째 자리로 들어오는 알파벳이 있으면
		if (!alpha[i]) {
			flag = true; break;
		}
	}
	if (flag) {
		ll min = INT64_MAX;
		int idx = 0;
		for (int i = 0; i < 10; i++) {
			if (!alpha[i] && chNum[i] < min) {
				min = chNum[i];
				idx = i;
			}
		}
		chNum[idx] = 0;
	}
	ll ans = 0;
	sort(chNum.begin(), chNum.end());
	for (int i = chNum.size() - 1; i >= 0; i--) {
		ans += chNum[i] * i;
	}
	printf("%lld\n", ans);
	return 0;
}