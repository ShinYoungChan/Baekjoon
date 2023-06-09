#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

vector<string> map;
vector<vector<bool>> visit;
vector<pair<int, int>> door;
vector<pair<int, int>> candi;
int key[26];
int dxdy[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
int h, w, ans, cnt;

void doorCheck() {
	for (int i = 0; i < w; i++) {
		if (map[0][i] == '.')door.push_back(make_pair(0, i));
		if (map[h - 1][i] == '.')door.push_back(make_pair(h - 1, i));
		if (map[0][i] == '$') {
			ans++; door.push_back(make_pair(0, i)); map[0][i] = '.';
		}
		if (map[h - 1][i]=='$') {
			ans++; door.push_back(make_pair(0, i)); map[h - 1][i] = '.';
		}
		if (map[0][i] >= 'a' && map[0][i] <= 'z') {
			key[map[0][i] - 'a']++;
			door.push_back(make_pair(0, i));
		}
		if (map[h - 1][i] >= 'a' && map[h - 1][i] <= 'z') {
			key[map[h - 1][i] - 'a']++;
			door.push_back(make_pair(h - 1, i));
		}
		if (map[0][i] >= 'A' && map[0][i] <= 'Z') {
			if (key[map[0][i] + 32 - 'a']) door.push_back(make_pair(0, i));
			else candi.push_back(make_pair(0, i));
		}
		if (map[h - 1][i] >= 'A' && map[h - 1][i] <= 'Z') {
			if (key[map[h - 1][i] + 32 - 'a']) door.push_back(make_pair(h - 1, i));
			else candi.push_back(make_pair(h - 1, i));
		}
	}
	for (int i = 0; i < h; i++) {
		if (map[i][0] == '.')door.push_back(make_pair(i, 0));
		if (map[i][w - 1] == '.')door.push_back(make_pair(i, w - 1));
		if (map[i][0] == '$') {
			ans++; door.push_back(make_pair(i, 0)); map[i][0] = '.';
		}
		if (map[i][w - 1] == '$') {
			ans++; door.push_back(make_pair(i, w - 1)); map[i][w - 1] = '.';
		}
		if (map[i][0] >= 'a' && map[i][0] <= 'z') {
			key[map[i][0] - 'a']++;
			door.push_back(make_pair(i, 0));
		}
		if (map[i][w - 1] >= 'a' && map[i][w - 1] <= 'z') {
			key[map[i][w - 1] - 'a']++;
			door.push_back(make_pair(i, w - 1));
		}
		if (map[i][0] >= 'A' && map[i][0] <= 'Z') {
			if (key[map[i][0] + 32 - 'a']) door.push_back(make_pair(i, 0));
			else candi.push_back(make_pair(i, 0));
		}
		if (map[i][w - 1] >= 'A' && map[i][w - 1] <= 'Z') {
			if (key[map[i][w - 1] + 32 - 'a']) door.push_back(make_pair(i, w - 1));
			else candi.push_back(make_pair(i, w - 1));
		}
	}
}

void reset() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			visit[i][j] = false;
	}
}

void navi() {
	reset();
	queue<pair<int, int>> q;
	cnt = 0;
	for (int i = 0; i < door.size(); i++) {
		q.push(make_pair(door[i].first, door[i].second));
		visit[door[i].first][door[i].second] = true;
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			int mx = x + dxdy[i][0];
			int my = y + dxdy[i][1];
			if (mx<0 || mx>h - 1 || my<0 || my>w - 1 || map[mx][my] == '*'||visit[mx][my])continue;
			if (map[mx][my] == '$') {
				map[mx][my] = '.';
				ans++; q.push(make_pair(mx, my)); visit[mx][my] = true;
			}
			if (map[mx][my] == '.') {
				q.push(make_pair(mx, my));
				visit[mx][my] = true;
			}
			if (map[mx][my] >= 'a' && map[mx][my] <= 'z') {
				key[map[mx][my] - 'a']++;
				q.push(make_pair(mx, my));
				visit[mx][my] = true;
				map[mx][my] = '.';
			}
			if (map[mx][my] >= 'A' && map[mx][my] <= 'Z') {
				if (key[map[mx][my] + 32 - 'a']) {
					q.push(make_pair(mx, my));
					visit[mx][my] = true;
					map[mx][my] = '.';
				}
			}
		}
	}
}

void init() {
	map.resize(h);
	visit.resize(h);
	candi.clear();
	door.clear();
	ans = 0;
	for (int i = 0; i < 26; i++)
		key[i] = 0;
}

void candiCheck() {
	for (auto it = candi.begin(); it != candi.end(); ) {
		if (key[map[it->first][it->second] + 32 - 'a']) {
			door.push_back(*it);
			it = candi.erase(it);
		}
		else {
			it++;
		}
	}
}

int main() {
	int test;
	cin >> test;
	while (test--) {
		cin >> h >> w;
		init();
		for (int i = 0; i < h; i++) {
			cin >> map[i];
			visit[i].resize(w);
		}
		string k;
		cin >> k;
		if (k != "0") {
			for (int i = 0; i < k.size(); i++) {
				key[k[i] - 'a']++;
			}
		}
		doorCheck();
		int prev = -1;
		while (true) {
			navi();
			if (prev == cnt)break;
			candiCheck();
			prev = cnt;
		}
		printf("%d\n", ans);
	}
	return 0;
}