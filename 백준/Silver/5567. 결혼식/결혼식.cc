#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> f[501];

void visit(int v, int s)
{
	queue<int> q;
	int level[501];
	for (int i = 0; i < 501; i++)
		level[i] = -1;
	q.push(s);
	level[s] = 0;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int i = 0; i < f[curr].size(); i++) {
			int next = f[curr][i];
			if (level[next] == -1) {
				q.push(next);
				level[next] = level[curr] + 1;
			}
		}
	}
	int count = 0;
	for (int i = 2; i <= v; i++) {
		if (level[i] < 3 && level[i] != -1)
			count++;
	}
	printf("%d\n", count);
}

int main(void)
{
	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		f[n1].push_back(n2);
		f[n2].push_back(n1);
	}
	visit(v, 1);
	return 0;
}