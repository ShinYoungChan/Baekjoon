#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

int dxdy[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
int landIdx = 0;
int scale[500][500];
bool visit[500][500];
map<int,int> mapping;

void bfs(int i, int j,vector<vector<int>> &land){
    int ground = 1;
    int n = land.size(), m = land[0].size();
    queue<pair<int,int>> q;
    q.push(make_pair(i,j));
    scale[i][j]=landIdx;
    visit[i][j]=true;
    while(!q.empty()){
        auto[x,y] = q.front();
        q.pop();
        for(int k=0;k<4;k++){
            int nx = x+dxdy[k][0];
            int ny = y+dxdy[k][1];
            if(nx<0||nx>n-1||ny<0||ny>m-1||visit[nx][ny]) continue;
            if(land[nx][ny]==1){
                visit[nx][ny]=true;
                q.push(make_pair(nx,ny));
                scale[nx][ny]=landIdx;
                ground++;
            }
        }
    }
    mapping[landIdx]=ground;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    for(int i=0;i<land.size();i++){
        for(int j=0;j<land[i].size();j++){
            if(visit[i][j]) continue;
            if(land[i][j]){
                bfs(i,j,land);
                landIdx++;
            }
        }
    }
    vector<bool> check(landIdx+1,false);
    for(int j=0;j<land[0].size();j++){
        int sum = 0;
        for(int k=0;k<check.size();k++){
            check[k]=false;
        }
        for(int i=0;i<land.size();i++){
            // 석유가 있고 채굴안한 곳인 경우
            if(land[i][j] && !check[scale[i][j]]){
                sum+=mapping[scale[i][j]];
                check[scale[i][j]]=true;
            }
        }
        if(answer<sum) answer=sum;
    }
    return answer;
}