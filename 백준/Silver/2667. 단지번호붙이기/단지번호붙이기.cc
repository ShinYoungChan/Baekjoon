#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> houseNum;
int house[25][25];
bool check[25][25];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int numbering = 0;
//재귀함수
void dfs(int x, int y, int v)
{
	if (x < 0 || y < 0 || x > v - 1 || y > v - 1)
		return;
	if (check[x][y] || house[x][y] == 0)
		return;
	check[x][y] = true;
	numbering++;
	dfs(x, y - 1, v);
	dfs(x - 1, y, v);
	dfs(x, y + 1, v);
	dfs(x + 1, y, v);
}

int bfs(int x, int y, int v)
{
	if (house[x][y] == 0 || check[x][y])
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
			if (mx >= 0 && mx < v && my >= 0 && my < v) {
				if (house[mx][my] == 1 && !check[mx][my]) {
					q.push({ mx,my });
					count++;
					check[mx][my] = true;
					house[mx][my] = count;
				}
			}
		}
	}
	return count;
}

int main(void)
{
	int v;
	cin >> v;
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++)
			scanf("%1d", &house[i][j]);
	}
	for (int x = 0; x < v; x++) {
		for (int y = 0; y < v; y++) {
			/*numbering = 0;
			dfs(x, y, v);
			if (numbering != 0)
				houseNum.push_back(numbering);*/
			int count = bfs(x, y, v);
			if (count != 0)
				houseNum.push_back(count);
		}
	}
	sort(houseNum.begin(), houseNum.end());
	cout << houseNum.size() << endl;
	for (auto x : houseNum)
		cout << x << endl;
	return 0;
}