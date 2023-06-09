#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

int main(void)
{
	int n;
	vector<tuple<int, int, int>>p1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		p1.push_back(make_tuple(i + 1, n - 1 - i, num));
	}
	sort(p1.begin(), p1.end(), greater<>());
	while (true) {
		bool c = true;
		for (int i = 0; i < p1.size(); i++) {
			if (get<1>(p1[i]) != get<2>(p1[i])) {
				get<1>(p1[i])--;
				tuple<int, int, int> temp = p1[i - 1];
				p1[i - 1] = p1[i];
				p1[i] = temp;
			}
		}
		for (int i = 0; i < p1.size(); i++) {
			if (get<1>(p1[i]) != get<2>(p1[i])) {
				c = false;
				break;
			}
		}
		if (c)
			break;
	}
	for (int i = 0; i < p1.size(); i++) {
		cout << get<0>(p1[i]) << " ";
	}
	return 0;
}