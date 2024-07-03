#include <string>
#include <vector>

using namespace std;

int dxdy[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
char ch[5] = {'d','l','r','u','\0'};
string ans = "";

int getDist(int x1, int y1, int x2, int y2){
    return abs(x1-x2)+abs(y1-y2);
}

void dfs(int n, int m, int x,int y, int r,int c, int k, int cnt, string str){
    if(ans.size()>0)return;
    if(k-cnt<getDist(x,y,r,c))return;
    if(x==r&&y==c&&cnt==k){
        ans = str;
        return;
    }
    
    for(int i=0;i<4;i++){
        int nx = x+dxdy[i][0];
        int ny = y+dxdy[i][1];
        if(nx<0||nx>n-1||ny<0||ny>m-1)continue;
        if((k-cnt-1-getDist(nx,ny,r,c))%2!=0)continue;
        dfs(n,m,nx,ny,r,c,k,cnt+1,str+ch[i]);
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    dfs(n,m,x-1,y-1,r-1,c-1,k,0,"");
    return ans.size()==0?"impossible":ans;
}