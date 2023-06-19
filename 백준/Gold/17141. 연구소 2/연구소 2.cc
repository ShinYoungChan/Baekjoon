#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int map[50][50];
int copymap[50][50];
int dxdy[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
queue<pair<int, int>> q;

void bfs() {
   while (!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      for (int i = 0; i < 4; i++) {
         int mx = x + dxdy[i][0];
         int my = y + dxdy[i][1];
         if (mx<0 || mx>n-1 || my<0 || my>n-1 || copymap[mx][my] == -1)continue;
         if (copymap[mx][my] == 0) {
            copymap[mx][my] = copymap[x][y] + 1;
            q.push({ mx,my });
         }
      }
   }
}

int check() {
   int max = 0;
   for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++) {
         if (copymap[i][j] == 0)
            return -1;
         if (max < copymap[i][j])
            max = copymap[i][j];
      }
   }
   return max;
}

void mapcopy() {
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
         copymap[i][j] = map[i][j];
   }
}

int main(void) {
   scanf("%d %d", &n, &m);
   vector<pair<int, int>> v;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         scanf("%d", &map[i][j]);
         if (map[i][j] == 1)
            map[i][j] = -1;
         if (map[i][j] == 2) {
            map[i][j] = 0;
            v.push_back({ i,j });
         }
      }
   }
   vector<bool>temp(v.size(), true);
   for (int i = 0; i < v.size() - m; i++)
      temp[i] = false;
   int min = 2100000000;
   do {
      mapcopy();
      for (int i = 0; i < v.size(); i++) {
         if (temp[i]) {
            copymap[v[i].first][v[i].second] = 1;
            q.push({ v[i].first,v[i].second });
         }
      }
      bfs();
      int time = check();
      if (time != -1 && min > time)
         min = time;
   } while (next_permutation(temp.begin(), temp.end()));
   if (min == 2100000000)
      printf("-1\n");
   else
      printf("%d\n", min - 1);
   return 0;
}