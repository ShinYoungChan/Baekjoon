#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    queue<pair<int,int>> q;
    vector<bool> visit(200000,false);
    q.push(make_pair(n,0));
    visit[n]=true;
    int ans = 0;
    while(!q.empty()){
        int curr = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(curr==k){
            ans=cnt;break;
        }
        int next = curr<<1;
        if(next<=200000 && !visit[next]){
            q.push(make_pair(next,cnt));
            visit[next]=true;
        }
        next = curr-1;
        if(next>=0 && !visit[next]){
            q.push(make_pair(next,cnt+1));
            visit[next]=true;
        }
        next = curr+1;
        if(next<=100000 && !visit[next]){
            q.push(make_pair(next,cnt+1));
            visit[next]=true;
        }
    }
    printf("%d\n",ans);
    return 0;
}