#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int main(void) {
	int arr[50][50];
	bool check[50][50];
	int N, M;
	int safety = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			scanf("%d", &arr[i][j]);
	}
	int dxdy[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int dist = 0;
			queue<tuple<int,int,int>> q;
			fill(&check[0][0], &check[N-1][M], false);
			q.push({ i,j,dist });
			while (!q.empty()) {
				int row = get<0>(q.front());
				int col = get<1>(q.front());
				int d = get<2>(q.front());
				q.pop();
				if (arr[row][col] == 1) {
					dist = d;
					break;
				}
				for (int k = 0; k < 8; k++) {
					int mx = dxdy[k][0];
					int my = dxdy[k][1];
					if (row + mx<0 || row + mx>N - 1 || col + my<0 || col + my>M - 1)
						continue;
					if (!check[row + mx][col + my]) {
						check[row + mx][col + my] = true;
						q.push({ row + mx,col + my,d + 1 });
					}
				}
			}
			if (safety < dist)
				safety = dist;
		}
	}
	printf("%d\n", safety);
	return 0;
}