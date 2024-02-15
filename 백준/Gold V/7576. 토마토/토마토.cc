#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int arr[1000][1000];

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	queue<pair<int, int>> q;
	int zero = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1)
				q.push({ i,j });
			if (arr[i][j] == 0)
				zero++;
		}
	}
	int dxdy[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
	int dist = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		dist = dist > arr[x][y] ? dist : arr[x][y];
		for (int i = 0; i < 4; i++) {
			int mx = x + dxdy[i][0];
			int my = y + dxdy[i][1];
			if (mx<0 || mx>m - 1 || my<0 || my>n - 1)continue;
			if (arr[mx][my] == 0) {
				q.push({ mx,my });
				arr[mx][my] = arr[x][y] + 1;
				zero--;
			}
		}
	}
	if (zero == 0)
		printf("%d\n", dist - 1);
	else
		printf("-1\n");
	return 0;
}