#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> home;
	vector<pair<int, int>> chicken;
	vector<int> com;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			scanf("%d", &a);
			if (a == 1)
				home.push_back({ i,j });
			if (a == 2)
				chicken.push_back({ i,j });
		}
	}
	for (int i = 0; i < m; i++)
		com.push_back(1);
	for (int i = 0; i < chicken.size() - m; i++)
		com.push_back(0);
	sort(com.begin(), com.end());
	int cdist = 2100000000;
	do {
		int asd = 0;
		for (int i = 0; i < home.size(); i++) {
			int d = 2100000000;
			for (int j = 0; j < com.size(); j++) {
				if (com[j] == 1) {
					int dist = abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second);
					d = d < dist ? d : dist;
				}
			}
			asd += d;
		}
		cdist = cdist < asd ? cdist : asd;
	} while (next_permutation(com.begin(), com.end()));

	printf("%d\n", cdist);
	return 0;
}