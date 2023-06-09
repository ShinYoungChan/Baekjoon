#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a[1001];
bool c[1001] = { false };

void dfs(int s)
{
	printf("%d ", s);
	c[s] = true;
	for (int i = 0; i < a[s].size(); i++) {
		int j = a[s][i];
		if (!c[j])
			dfs(j);
	}
}

void bfs(int s)
{
	printf("\n");
	queue<int> q;
	q.push(s);
	bool check[1001] = { false };
	check[s] = true;
	while (!q.empty())
	{
		int n = q.front();
		q.pop();
		printf("%d ", n);
		for (int i = 0; i < a[n].size(); i++) {
			int j = a[n][i];
			if (!check[j]) {
				q.push(j);
				check[j] = true;
			}
		}
	}
	printf("\n");
}

int main(void)
{
	int v, e, s;
	cin >> v >> e >> s;
	for (int i = 0; i < e; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		a[n1].push_back(n2);
		a[n2].push_back(n1);
	}
	for (int i = 1; i <= v; i++) {
		if (!a[i].empty())
			sort(a[i].begin(), a[i].end());
	}
	dfs(s);
	bfs(s);
	return 0;
}