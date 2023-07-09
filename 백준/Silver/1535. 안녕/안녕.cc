#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> people;
vector<int> happy;
int maxhappy = 0;

void dfs(int life, int health, int index) {
	if (life <= 0 || index > people.size() - 1) {
		maxhappy = maxhappy > health ? maxhappy : health;
		return;
	}
	//인사 할 경우
	if (life - people[index] > 0)
		dfs(life - people[index], health + happy[index], index + 1);
	//인사 안 할 경우
	dfs(life, health, index + 1);
}

int main(void) {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int n;
		scanf("%d", &n);
		people.push_back(n);
	}
	for (int i = 0; i < N; i++) {
		int n;
		scanf("%d", &n);
		happy.push_back(n);
	}
	dfs(100, 0, 0);
	printf("%d\n", maxhappy);
	return 0;
}