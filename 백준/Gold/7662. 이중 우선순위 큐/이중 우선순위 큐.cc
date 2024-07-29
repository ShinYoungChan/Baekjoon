#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

priority_queue<int> maxQ;
priority_queue<int, vector<int>, greater<int>> minQ;
unordered_map<int, int> um;

void EnQueue(int num) {
	maxQ.push(num);
	minQ.push(num);
	um[num]++;
}

void OutQueue(int num) {
	if (num == 1) {
		if (!maxQ.empty()) {
			um[maxQ.top()]--;
			maxQ.pop();
		}
	}
	else {
		if (!minQ.empty()) {
			um[minQ.top()]--;
			minQ.pop();
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int test;
	cin >> test;

	for (int t = 0; t < test; t++) {
		int k;
		cin >> k;

		while (!maxQ.empty())maxQ.pop();
		while (!minQ.empty())minQ.pop();
		um.clear();
		for (int i = 0; i < k; i++) {
			char ch;
			int num;
			cin >> ch >> num;
			if (ch == 'I') {
				EnQueue(num);
			}
			else {
				OutQueue(num);
				while (!maxQ.empty() && um[maxQ.top()] == 0) maxQ.pop();
				while (!minQ.empty() && um[minQ.top()] == 0) minQ.pop();
			}
		}
		while (!maxQ.empty() && um[maxQ.top()] == 0) maxQ.pop();
		while (!minQ.empty() && um[minQ.top()] == 0) minQ.pop();

		if (maxQ.empty() || minQ.empty()) cout << "EMPTY\n";
		else cout << maxQ.top() << " " << minQ.top() << "\n";
	}
	return 0;
}