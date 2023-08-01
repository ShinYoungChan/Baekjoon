#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int map[100][100];
bool check[100][100];
int dxdy[4][2]={{-1,0},{0,-1},{1,0},{0,1}};

void reset(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            check[i][j]=false;
        }
    }
}

bool bfs(int n, int i, int j, int h){
    if(check[i][j]||map[i][j]<=h)return false;
    queue<pair<int,int>> q;
    q.push(make_pair(i,j));
    check[i][j]=true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int mx = x + dxdy[k][0];
            int my = y + dxdy[k][1];
            if(mx<0||mx>n-1||my<0||my>n-1||check[mx][my])continue;
            if(map[mx][my]<=h)continue;
            q.push(make_pair(mx,my));
            check[mx][my]=true;
        }
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    set<int> s;
    vector<int> v(1,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
            s.insert(map[i][j]);
        }
    }
    for(auto a:s){
        v.push_back(a);
    }
    int maxland = 1;
    int idx = 0;
    while(idx++<v.size()){
        int land = 0;
        reset(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(bfs(n,i,j,v[idx])){
                    land++;
                }
            }
        }
        if(maxland<land)
            maxland=land;
    }
    printf("%d\n",maxland);
    return 0;
}