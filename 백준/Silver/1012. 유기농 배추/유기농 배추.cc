#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int garden[50][50];
bool check[50][50];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int numbering = 0;
void dfs(int x, int y, int n, int m)
{
	if (x  < 0 || y  < 0 || x > n - 1 || y > m - 1)
		return;
	if (check[x][y] || garden[x][y] == 0)
		return;
	check[x][y] = true;
	numbering++;
	dfs(x, y - 1, n, m);
	dfs(x - 1, y, n, m);
	dfs(x, y + 1, n, m);
	dfs(x + 1, y, n, m);
}
int bfs(int x, int y, int n, int m)
{
	if (garden[x][y] == 0 || check[x][y])
		return 0;
	queue<pair<int, int>> q;
	q.push({ x,y });
	check[x][y] = true;
	int count = 1;
	while (!q.empty()) {
		int n1 = q.front().first;
		int n2 = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int mx = n1 + dx[i];
			int my = n2 + dy[i];
			if (mx >= 0 && mx < n && my >= 0 && my < m) {
				if (garden[mx][my] == 1 && !check[mx][my]) {
					q.push({ mx,my });
					count++;
					check[mx][my] = true;
				}
			}
		}
	}
	return count;
}

int main(void)
{
	int t;
	cin >> t;
	for (int test = 0; test < t; test++) {
		int m, n, k;
		cin >> m >> n >> k;
		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 50; j++) {
				garden[i][j] = 0;
				check[i][j] = false;
			}
		}
		for (int i = 0; i < k; i++) {
			int n1, n2;
			cin >> n1 >> n2;
			garden[n2][n1] = 1;
		}
		int count = 0;
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < m; y++) {
				if (bfs(x, y, n, m))
					count++;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}