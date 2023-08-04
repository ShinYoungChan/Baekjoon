#include <iostream>
#include <tuple>
#include <vector>
#include <queue>

using namespace std;

int map[300][300];
bool check[300][300];
int dxdy[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
vector<pair<int,int>>v;
vector<tuple<int,int,int>> melts;

void seaCheck(int n,int m){
    for(int i=0;i<v.size();i++){
        int x = v[i].first;
        int y = v[i].second;
        int count = 0;
        for(int j=0;j<4;j++){
            int mx = x+dxdy[j][0];
            int my = y+dxdy[j][1];
            if(mx<0||mx>n-1||my<0||my>m-1)continue;
            if(map[mx][my]==0)
                count++;
        }
        melts.push_back(make_tuple(x,y,count));
    }
}

void melt(){
    auto vit = v.begin();
    for (auto mit = melts.begin(); mit != melts.end();) {
        int x = get<0>(*mit);
        int y = get<1>(*mit);
        int count = get<2>(*mit);
        map[x][y] = map[x][y] > count ? map[x][y]-count : 0;
        if (map[x][y]==0) {
            mit = melts.erase(mit);
            vit=v.erase(vit);
        }
        else {
            mit++;
            vit++;
        }
    }   
}

bool bfs(int x,int y,int n,int m){
    if(check[x][y])
        return false;
    queue<pair<int,int>> q;
    q.push({x,y});
    check[x][y]=true;
    while(!q.empty()){
        int currx = q.front().first;
        int curry = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int mx = currx+dxdy[i][0];
            int my = curry+dxdy[i][1];
            if(mx<0||mx>n-1||my<0||my>m-1)continue;
            if(map[mx][my]!=0&&!check[mx][my]){
                q.push({mx,my});
                check[mx][my]=true;
            }
        }
    }
    return true;
}

int main(void){
    // 0확인 -> 녹이기 -> 체크
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&map[i][j]);
            if(map[i][j]!=0){
                v.push_back({i,j});
            }
            check[i][j]=false;
        }
    }
    int year = 0;
    int lump = 0;
    while(v.size()!=0){
        year++;
        lump = 0;
        melts.clear();
        seaCheck(n,m);
        melt();
        for(int i=0;i<v.size();i++){
            int x = v[i].first;
            int y = v[i].second;
            if(bfs(x,y,n,m))
                lump++;
        }
        if(lump>1)
            break;
        for(int i=0;i<v.size();i++){
            int x = v[i].first;
            int y = v[i].second;
            check[x][y]=false;
        }
    }
    if(lump <= 1)
        printf("0\n");
    else 
        printf("%d\n",year);
    return 0;
}