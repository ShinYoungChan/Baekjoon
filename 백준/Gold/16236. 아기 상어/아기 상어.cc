#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int map[20][20];
int yammy[20][20];
bool visit[20][20];
int dxdy[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
int shark = 2;
int length, row, col;
bool help = true;
queue<pair<int,int>> q;

void bfs(int n){
    map[q.front().first][q.front().second]=0;
    visit[q.front().first][q.front().second]=true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int mx = x+dxdy[i][0];
            int my = y+dxdy[i][1];
            if(mx<0||mx>n-1||my<0||my>n-1||visit[mx][my])continue;
            if(shark<map[mx][my])continue;
            q.push(make_pair(mx,my));
            yammy[mx][my] = yammy[x][y]+1;
            visit[mx][my]=true;
            // printf("mx = %d, my = %d\n",mx,my);
            if(shark>map[mx][my]&&map[mx][my]!=0){
                help = false;
                if(yammy[mx][my]<length){
                    length = yammy[mx][my];
                    row = mx; col= my;
                }
                else if(yammy[mx][my]==length){
                    // printf("mx - x = %d\n",mx-x);
                    // if(mx-x>=0)continue;
                    if(row>mx){
                        row=mx;
                        col = my;
                    }
                    else if(row==mx)
                        col = col < my ? col : my;
                    // printf("here\n");
                }
                // printf("bfs row = %d, col = %d\n",row,col);
            }
        }
    }
}

void reset(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visit[i][j]=false;
            yammy[i][j]=0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
            if(map[i][j]==9){
                q.push(make_pair(i,j));
                map[i][j]=0;
            }
        }
    }
    int time = 0;
    int cnt = 0;
    while(true){
        reset(n);
        help = true;
        length=21000000;
        row = col = n;
        bfs(n);
        // printf("time = %d, length = %d\n",time,length);
        if(help)break;
        time+=length;cnt++;
        // printf("row = %d, col = %d, shark = %d, cnt = %d\n",row,col,shark,cnt);
        q.push(make_pair(row,col));
        map[row][col]=0;
        if(cnt==shark){
            shark++;cnt=0;
        }
    }
    cout<<time<<"\n";
    return 0;
}