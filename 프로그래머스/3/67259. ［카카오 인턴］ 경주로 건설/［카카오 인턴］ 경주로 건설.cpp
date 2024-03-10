#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
#define INF 2100000000

using namespace std;

class track{
public:
    int x,y,cnt,dir;
public:
    track(int _x,int _y, int _cnt, int _dir){
        x=_x; y=_y; cnt=_cnt; dir=_dir;
    }
};

// cnt 오름차순
struct cmp{
    bool operator() (track &a, track &b){
        return a.cnt > b.cnt;
    }
};

int dxdy[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

int solution(vector<vector<int>> board) {
    int answer = INF, n = board.size()-1, m = board[0].size()-1;
    priority_queue<track, vector<track>, cmp> pq;
    vector<vector<vector<int>>> dist(n+1,vector<vector<int>>(m+1,vector<int>(4,INF)));
    for(int i=0;i<4;i++){
        pq.push(track(0,0,0,i));
        dist[0][0][i]=0;
    }
    while(!pq.empty()){
        auto[x,y,cnt,dir] = pq.top();
        pq.pop();
        for(int i=0;i<4;i++){
            int nx = x + dxdy[i][0];
            int ny = y + dxdy[i][1];
            if(nx<0||nx>n||ny<0||ny>m||board[nx][ny]==1)continue;
            int cost = 0;
            // 진행방향이 같은 경우
            if(dir==i){
                cost = 100;
            }
            // 진행방향이 다른 경우
            else{
                cost = 600;
            }
            if(dist[nx][ny][i] > cnt+cost){
                dist[nx][ny][i] = cnt+cost;
                pq.push(track(nx,ny,cnt+cost,i));
            }
        }
    }
    for(int i=0;i<4;i++){
        if(answer>dist[n][m][i])
            answer=dist[n][m][i];
    }
    return answer;
}