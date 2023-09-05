#include <string>
#include <vector>
#include <queue>

using namespace std;

int dxdy[4][2]={{-1,0},{0,-1},{1,0},{0,1}};

int solution(vector<string> board) {
    int answer = -1;
    int n = board.size();
    int m = board[0].size();
    vector<vector<bool>> visit(n,vector<bool>(m,false));
    queue<pair<pair<int,int>,int>> q;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            if(board[i][j]=='R'){
                q.push(make_pair(make_pair(i,j),0));
            }
        }
    }
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        if(board[x][y]=='G'){
            answer=cnt;break;
        }
        q.pop();
        for(int i=0;i<4;i++){
            int mx = x+dxdy[i][0];
            int my = y+dxdy[i][1];
            while(true){
                if(mx<0||mx>n-1||my<0||my>m-1||board[mx][my]=='D'){
                    mx -=dxdy[i][0];
                    my -=dxdy[i][1];
                    if(!visit[mx][my]){
                        q.push(make_pair(make_pair(mx,my),cnt+1));
                        visit[mx][my]=true;
                    }
                    break;
                }
                mx+=dxdy[i][0];
                my+=dxdy[i][1];
            }
        }
    }
    return answer;
}