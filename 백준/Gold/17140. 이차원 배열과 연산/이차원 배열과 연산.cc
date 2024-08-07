#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int r, c, k;
vector<vector<int>> v(100, vector<int>(100));

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

void rowSort() {
	unordered_map<int, int> um;
	vector<vector<pair<int, int>>> row(v.size());

	for (int i = 0; i < v.size(); i++) {
		um.clear();
		for (int j = 0; j < v[0].size(); j++) {
			um[v[i][j]]++;
		}
		for (auto a : um) {
			if (a.first == 0)continue;
			row[i].push_back(make_pair(a.first, a.second));
		}
		sort(row[i].begin(), row[i].end(), cmp);
	}

	vector<vector<int>> cv(100, vector<int>(100));
	for (int i = 0; i < row.size(); i++) {
		for (int j = 0, k = 0; j < row[i].size(); j++, k += 2) {
			cv[i][k] = row[i][j].first;
			cv[i][k + 1] = row[i][j].second;
		}
	}

	v = cv;
}

vector<vector<int>> rotateVector(vector<vector<int>> &map) {
	int rc = map.size();
	int cc = map[0].size();

	vector<vector<int>> cv(cc, vector<int>(rc));

	// 행열 전환
	for (int i = 0; i < rc; i++) {
		for (int j = 0; j < cc; j++) {
			cv[j][i] = map[i][j];
		}
	}

	return cv;
}

void colSort() {
	vector<vector<int>> cv = rotateVector(v);

	unordered_map<int, int> um;
	vector<vector<pair<int, int>>> row(cv.size());
	for (int i = 0; i < cv.size(); i++) {
		um.clear();
		for (int j = 0; j < cv[i].size(); j++) {
			um[cv[i][j]]++;
		}
		for (auto a : um) {
			if (a.first == 0)continue;
			row[i].push_back(make_pair(a.first, a.second));
		}
		sort(row[i].begin(), row[i].end(), cmp);
	}

	vector<vector<int>> ccv(100, vector<int>(100));
	for (int i = 0; i < row.size(); i++) {
		for (int j = 0, k = 0; j < row[i].size(); j++, k += 2) {
			ccv[i][k] = row[i][j].first;
			ccv[i][k + 1] = row[i][j].second;
		}
	}

	// 행 열 전환
	v = rotateVector(ccv);
}

bool findRowCol() {
	int rCnt = 0;
	int cCnt = 0;
	for (int i = 0; i < 100; i++) {
		int rc = 0, cc = 0;
		for (int j = 0; j < 100; j++) {
			if (v[i][j] != 0)cc++;
			if (v[j][i] != 0)rc++;
		}
		if (rc > rCnt)rCnt = rc;
		if (cc > cCnt)cCnt = cc;
	}
	return rCnt >= cCnt ? true : false;
}

int main() {
	cin >> r >> c >> k;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> v[i][j];
		}
	}

	int time = 0;
	while (v[r - 1][c - 1] != k && time <= 100) {
		// 행 갯수 >= 열 갯수
		if (findRowCol()) {
			rowSort();
		}
		// 행 갯수 < 열 갯수
		else {
			colSort();
		}
		time++;
	}

	printf("%d\n", time > 100 ? -1 : time);
	return 0;
}