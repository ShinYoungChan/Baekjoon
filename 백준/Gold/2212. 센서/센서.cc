#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n, k;
	scanf("%d", &n);
	scanf("%d", &k);
	vector<int> people;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		people.push_back(a);
	}
	sort(people.begin(), people.end());
	vector<int> v;
	for (int i = 1; i < people.size(); i++) {
		v.push_back(people[i] - people[i - 1]);
	}
	sort(v.begin(), v.end());
	int sum = 0;
	for (int i = 0; i < n - k; i++)
		sum += v[i];
	printf("%d\n", sum);
	return 0;
}