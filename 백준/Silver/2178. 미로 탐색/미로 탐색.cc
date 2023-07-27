#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int maze[100][100];
bool check[100][100];
int cnt[100][100];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

void bfs(int x, int y, int n, int m)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	check[x][y] = true;
	int count = 1;
	cnt[x][y] = count;
	while (!q.empty()) {
		bool isNode = false;
		int n1 = q.front().first;
		int n2 = q.front().second;
		q.pop();
		int mX;
		int mY;
		for (int i = 0; i < 4; i++) {
			mX = n1 + dx[i];
			mY = n2 + dy[i];
			if (mX >= 0 && mX < n && mY >= 0 && mY < m) {
				if (maze[mX][mY] == 1 && !check[mX][mY]) {
					check[mX][mY] = true;
					isNode = true;
					count++;
					cnt[mX][mY] = cnt[n1][n2] + 1;
					q.push({ mX,mY });
				}
			}
		}
	}
	printf("%d\n", cnt[n - 1][m - 1]);
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			scanf("%1d", &maze[i][j]);
	}
	bfs(0, 0, n, m);
	return 0;
}