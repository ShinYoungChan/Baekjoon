#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n + 1, 0);
	unordered_set<int> s;
	for (int i = 0; i < m; i++) {
		int order, train, seat;
		cin >> order;
		if (order <= 2) {
			cin >> train >> seat;
			if (order == 1) v[train] |= (1 << seat);
			else v[train] &= ~(1 << seat);
		}
		else {
			cin >> train;
			if (order == 3) {
				v[train] <<= 1; v[train] &= ((1 << 21) - 1);
			}
			else {
				v[train] >>= 1; v[train] &= ~1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		s.insert(v[i]);
	}
	printf("%d\n", s.size());
	return 0;
}