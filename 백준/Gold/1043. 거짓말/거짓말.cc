#include <iostream>
#include <vector>

using namespace std;

int Root[51], Rank[51], truth[51];
vector<int> party[51];

int Find(int a) {
	if (a == Root[a]) return a;
	return Root[a] = Find(Root[a]);			// Path Compression
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	
    // Union by Rank
	if (Rank[a] < Rank[b]) Root[a] = b;
	else Root[b] = a;
	if (Rank[a] == Rank[b]) Rank[a]++;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// Root 배열 초기화
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) Root[i] = i;

	// 진실 아는 사람 배열
	int tr_num;
	cin >> tr_num;
	for (int i = 0; i < tr_num; i++) {
		cin >> truth[i];
	}

	// 파티 정보
	for (int i = 0; i < m; i++) {
		int num, idx;
		cin >> num;
		for (int j = 0; j < num; j++) {
			cin >> idx;
			party[i].push_back(idx);
		}
	}

	// 각 파티별 집합
	for (int i = 0; i < m; i++) {
		for (int j = 1; j < party[i].size(); j++) {
			Union(party[i][j - 1], party[i][j]);
		}
	}

	// 각 파티별 대표와 진실 아는 사람끼리 일치여부 확인
	int ans = 0;
	for (int i = 0; i < m; i++) {
		bool isValid = true;
		for (int j = 0; j < tr_num; j++) {
			if (Find(truth[j]) == Find(party[i][0])) {
				isValid = false;
				break;
			}
		}
		if (isValid) ans++;
	}
	cout << ans;

	return 0;
}