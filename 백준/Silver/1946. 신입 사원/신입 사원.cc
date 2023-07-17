#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int people;
		vector<pair<int, int>>em;
		scanf("%d", &people);
		for (int j = 0; j < people; j++) {
			int num1, num2;
			scanf("%d %d", &num1, &num2);
			em.push_back(make_pair(num1, num2));
		}
		sort(em.begin(), em.end());

		int count = 1;
		int high = em[0].second;
		for (int j = 1; j < em.size(); j++) {
			if (high > em[j].second) {
				count++;
				high = em[j].second;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}