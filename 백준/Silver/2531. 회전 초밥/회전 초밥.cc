#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, d, k, c;
	cin >> n >> d >> k >> c;
	vector<int> v(n), sushi(d + 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int ans = 0;
	for (int i = 0; i < k; i++) {
		if (sushi[v[i]] == 0) {
			ans++;
		}
		sushi[v[i]]++;
	}
	int cnt = ans;
    if (sushi[c]==0) ans++;
	for (int i = k; i < n + k - 1; i++) {
		sushi[v[i - k]]--;
		if (sushi[v[i - k]] == 0) {
			cnt--;
		}
		if (sushi[v[i % n]] == 0) {
			cnt++;
		}
		sushi[v[i % n]]++;
		int flag = 0;
		if (sushi[c] == 0) {
			flag = 1;
		}
		if (ans < cnt + flag) ans = cnt + flag;
	}
	cout << ans << endl;
	return 0;
}