#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

bool bfs(vector<string> str, int i, int j)
{
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    bool check[5][5]={false};
    queue<tuple<int,int,int>>q;
    q.push(make_tuple(i,j,0));
    check[i][j]=true;
    while(!q.empty()){
        int x,y,cnt;
        tie(x,y,cnt) = q.front();
        q.pop();
        for(int k=0;k<4;k++){
            int mx=x+dx[k];
            int my=y+dy[k];
            if(mx<0||mx>4||my<0||my>4||str[mx][my]=='X')continue;
            if(!check[mx][my]){
                if(str[mx][my]=='O'){
                    q.push(make_tuple(mx,my,cnt+1));
                }
                check[mx][my]=true;
                if(str[mx][my]=='P'){
                    if(cnt+1<=2)
                        return false;
                    q.push(make_tuple(mx,my,cnt+1));
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i=0;i<places.size();i++){
        bool yes = true;
        for(int j=0;j<places[i].size();j++){
            for(int k=0;k<places[i][j].length();k++){
                if(places[i][j][k]=='P'){
                    if(!bfs(places[i],j,k)){
                        yes=false;
                        break;
                    }
                }
            }
        }
        if(yes)
            answer.push_back(1);
        else
            answer.push_back(0);
    }
    return answer;
}