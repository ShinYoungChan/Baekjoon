#include <iostream>
#include <vector>

using namespace std;

int findParent(vector<int> v, int node1, int node2) {
	vector<bool> visit(v.size(), false);
	while (node1 != 0) {
		visit[node1] = true;
		// 부모 노드로 올라감.
		node1 = v[node1];
	}
	while (node2 != 0) {
		if (visit[node2]) {
			return node2;
		}
		visit[node2] = true;
		// 부모 노드로 올라감.
		node2 = v[node2];
	}
}

int main() {
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		int n;
		cin >> n;
		vector<int> v(n + 1, 0);

		// n-1개의 간선 입력 받기
		for (int i = 0; i < n - 1; i++) {
			int parent, child;
			cin >> parent >> child;
			v[child] = parent;
		}
		int node1, node2;
		cin >> node1 >> node2;
		printf("%d\n", findParent(v, node1, node2));
	}
	return 0;
}