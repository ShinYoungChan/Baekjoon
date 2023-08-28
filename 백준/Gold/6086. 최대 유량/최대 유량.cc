#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

#define MAX 150
#define INF 2100000000

/*1. 가능한 경로를 다 찾는다.(bfs를 통해)
2. 1.에서 찾은 모든 경로에 대해서 최대 유량을 구한다.
3. 2.에서 찾은 최대 유량들의 합을 구한다.*/

vector<int> a[MAX];
int c[MAX][MAX];
int f[MAX][MAX];
int path[MAX];
int MaxFlowResult;

void MaxFlow(int start, int end) {
	queue<int> q;
	while (1) {
		for (int i = 0; i < MAX; i++)
			path[i] = -1;

		q.push(start);
		path[start] = 0;
		while (!q.empty()) {
			int curr = q.front();
			q.pop();
			for (int i = 0; i < a[curr].size(); i++) {
				int next = a[curr][i];
				if (path[next] == -1 && c[curr][next] - f[curr][next] > 0) {
					q.push(next);
					path[next] = curr;
				}
			}

		}
		if (path[end] == -1)
			break;
		int flow = INF;
		for (int i = end; i != start; i = path[i]) {
			if (flow > c[path[i]][i] - f[path[i]][i])
				flow = c[path[i]][i] - f[path[i]][i];
		}
		for (int i = end; i != start; i = path[i]) {
			f[path[i]][i] += flow;
			f[i][path[i]] -= flow;
		}
		MaxFlowResult += flow;
	}
	printf("%d\n", MaxFlowResult);
}

int main(void) {
	int v;
	scanf("%d", &v);

	for (int i = 0; i < v; i++) {
		int num1, num2, capacity;
		char a1, a2;
		cin >> a1 >> a2 >> capacity;
		num1 = a1 - 'A';
		num2 = a2 - 'A';
		a[num1].push_back(num2);
		a[num2].push_back(num1);
		c[num1][num2] += capacity;
		c[num2][num1] += capacity;
	}
	MaxFlow(0, 25);

	return 0;
}