#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
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
	int front = 0, rear = k, cnt = ans;
	while (front != n - 1 || rear != k - 1) {
		sushi[v[front]]--;
		if (sushi[v[front]] == 0) {
			cnt--;
		}
		if (sushi[v[rear]] == 0) {
			cnt++;
		}
		sushi[v[rear]]++;
		int flag = 0;
		if (sushi[c] == 0) {
			flag = 1;
		}
		if (ans < cnt + flag) ans = cnt + flag;
		front++;
		rear = (rear + 1) % n;
	}
	cout << ans << endl;
	return 0;
}