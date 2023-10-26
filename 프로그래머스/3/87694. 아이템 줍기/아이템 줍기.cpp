#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int map[102][102];
int dxdy[4][2]={{-1,0},{0,-1},{1,0},{0,1}};

void fill(int x1, int y1, int x2, int y2){
    for(int i=x1*2;i<=x2*2;i++){
        for(int j=y1*2;j<=y2*2;j++){
            map[i][j] = 1;
        }
    }
}

void empty(int x1, int y1, int x2, int y2){
    for(int i=x1*2+1;i<=x2*2-1;i++){
        for(int j=y1*2+1;j<=y2*2-1;j++){
            map[i][j] = 0;
        }
    }
}

void bfs(int i, int j){
    queue<pair<int,int>> q;
    q.push(make_pair(i*2,j*2));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int mx = x+dxdy[k][0];
            int my = y+dxdy[k][1];
            if(mx<1||mx>101||my<1||my>101)continue;
            if(!map[mx][my]||map[mx][my]>1)continue;
            map[mx][my]=map[x][y]+1;
            q.push(make_pair(mx,my));
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    for(int i=0;i<rectangle.size();i++){
        fill(rectangle[i][0],rectangle[i][1],rectangle[i][2],rectangle[i][3]);
    }
    for(int i=0;i<rectangle.size();i++){
        empty(rectangle[i][0],rectangle[i][1],rectangle[i][2],rectangle[i][3]);
    }
    bfs(characterX, characterY);
    return map[itemX*2][itemY*2]/2;
}