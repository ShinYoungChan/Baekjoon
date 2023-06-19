#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int map[50][50];
int cmap[50][50];
bool visit[50][50];
int dxdy[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
queue<pair<int, int>> q;
queue<pair<int, int>> nq;

void copy(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cmap[i][j] = map[i][j];
        }
    }
}

void bfs(int n) {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int mx = x + dxdy[i][0];
            int my = y + dxdy[i][1];
            if (mx<0 || mx>n - 1 || my<0 || my>n - 1)continue;
            if (cmap[mx][my] > 0)continue;
            cmap[mx][my] = cmap[x][y] + 1;
            q.push(make_pair(mx, my));
        }
    }
}

int check(int n) {
    while (!nq.empty()) {
        int x = nq.front().first;
        int y = nq.front().second;
        nq.pop();
        cmap[x][y] = -1;
    }
    int time = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cmap[i][j] == 0)return -1;
            if (time < cmap[i][j])
                time = cmap[i][j];
        }
    }
    return time;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                v.push_back(make_pair(i, j));
                map[i][j] = 0;
            }
        }
    }
    vector<bool> chk(v.size(), false);
    for (int i = v.size()-m; i < v.size(); i++) {
        chk[i] = true;
    }
    int minTime = 210000000;
    do {
        copy(n);
        for (int i = 0; i < v.size(); i++) {
            if (chk[i]) {
                cmap[v[i].first][v[i].second] = 1;
                q.push(make_pair(v[i].first, v[i].second));
            }
            else {
                nq.push(make_pair(v[i].first, v[i].second));
            }
        }
        bfs(n);
        int time = check(n);
        if(time!=-1){
            minTime = minTime < time ? minTime : time;
        }
    } while (next_permutation(chk.begin(), chk.end()));
    if (minTime == 210000000) {
        cout << -1 << "\n";
    }
    else {
        cout << minTime - 1 << "\n";
    }
    return 0;
}