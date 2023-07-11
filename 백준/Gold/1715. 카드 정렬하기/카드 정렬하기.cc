#include <iostream>
#include <queue>

using namespace std;

int main() {
	/*int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int sum = 0;
	int ans = 0;
	if (v.size() >= 2) {
		ans = sum = v[0] + v[1];
		for (int i = 2; i < v.size(); i++) {
			sum = sum + v[i];
			ans += sum;
		}
	}
	printf("%d\n", ans);*/
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>>pq;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}
	int ans = 0;
	int sum = 0;
	if (pq.size() >= 2) {
		while (pq.size()>1) {
			int n1 = pq.top(); pq.pop();
			int n2 = pq.top(); pq.pop();
			ans += n1 + n2;
			pq.push(n1 + n2);
		}
	}
	printf("%d\n", ans);
	return 0;
}