#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> a[101];

void bfs(int s)
{
	queue<int> q;
	q.push(s);
	bool check[101] = { false };
	check[s] = true;
	int count = 0;
	while (!q.empty())
	{
		int n = q.front();
		q.pop();
		for (int i = 0; i <a[n].size(); i++) {
			int j = a[n][i];
			if (!check[j]) {
				q.push(j);
				check[j] = true;
				count++;
			}
		}
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
		a[n1].push_back(n2);
		a[n2].push_back(n1);
	}
	bfs(1);
	return 0;
}