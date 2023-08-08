#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int getparent(int node) {
	if (parent[node] == node) return node;
	return parent[node] = getparent(parent[node]);
}

void unionparent(int a, int b) {
	a = getparent(a);
	b = getparent(b);
	if (a < b)parent[b] = a;
	else parent[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	parent.resize(n + 1);
	vector<int> city(m);
	for (int i = 1; i <= n; i++)
		parent[i] = i;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			if (a) unionparent(i + 1, j + 1);
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> city[i];
	}
	bool flag = true;
	for (int i = 1; i < city.size(); i++) {
		if (parent[city[0]] != parent[city[i]]) {
			flag = false; break;
		}
	}
	printf("%s\n", flag == true ? "YES" : "NO");
	return 0;
}