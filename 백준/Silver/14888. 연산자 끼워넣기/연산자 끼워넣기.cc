#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int oper[4];
int maxAns = -2100000000;
int minAns = 2100000000;

int operation(int n1, int n2, int op) {
	if (op == 0) {
		return n1 + n2;
	}
	else if (op == 1) {
		return n1 - n2;
	}
	else if (op == 2) {
		return n1 * n2;
	}
	return n1 / n2;
}

void dfs(int n, int cnt) {
	if (cnt == v.size()) {
		if (maxAns < n) maxAns = n;
		if (minAns > n) minAns = n;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (oper[i] > 0) {
			oper[i]--;
			dfs(operation(n, v[cnt], i), cnt + 1);
			oper[i]++;
		}
	}
}

int main() {
	int n;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}
	dfs(v[0], 1);
	printf("%d\n%d\n", maxAns, minAns);
	return 0;
}