#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, truth;
vector<vector<int>> v;
queue<int> q;

int main() {
	cin >> n >> m >> truth;
	v.resize(m);
	for (int i = 0; i < truth; i++) {
		int num;
		cin >> num;
		q.push(num);
	}

	// 파티에 오는 사람 입력 받기
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		v[i].resize(num);
		for (int j = 0; j < num; j++) {
			cin >> v[i][j];
		}
	}

	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (auto it = v.begin(); it != v.end();) {
			if (find(it->begin(), it->end(), curr) != it->end()) {
				for (auto a : *it)q.push(a);
				it = v.erase(it);
			}
			else {
				it++;
			}
		}
	}
	cout << v.size() << "\n";
	return 0;
}