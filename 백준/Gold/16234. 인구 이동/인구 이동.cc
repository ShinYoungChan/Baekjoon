#include <iostream>
#include <queue>

using namespace std;

int n,l,r;
int map[100][100];
bool visit[100][100];
int dxdy[4][2]={{-1,0},{0,-1},{1,0},{0,1}};

bool bfs(int i, int j){
    if(visit[i][j])return false;
    visit[i][j]=true;
    queue<pair<int,int>> q;
    vector<pair<int,int>> v;
    v.push_back(make_pair(i,j));
    q.push(make_pair(i,j));
    int sum = map[i][j];
    int cnt = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int mx = x+dxdy[k][0];
            int my = y+dxdy[k][1];
            if(mx<0||mx>n-1||my<0||my>n-1||visit[mx][my])continue;
            int diff = abs(map[x][y]-map[mx][my]);
            if(diff<l||diff>r)continue;
            visit[mx][my]=true;
            q.push(make_pair(mx,my));
            v.push_back(make_pair(mx,my));
            sum+=map[mx][my];
            cnt++;
        }
    }
    if(v.size()==1)return false;
    sum /= cnt;
    for(int i=0;i<v.size();i++){
        map[v[i].first][v[i].second] = sum;
    }
    return true;
}

void reset(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            visit[i][j]=false;
    }
}

int main(){
    cin>>n>>l>>r;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    int day = -1;
    bool chk = true;
    while(chk){
        chk = false;
        reset();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(bfs(i,j)) chk = true;
            }
        }
        day++;
    }
    printf("%d\n",day);
    return 0;
}