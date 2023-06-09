#include <iostream>
#include <queue>
#define INF 2100000000

using namespace std;

vector<vector<int>> v;

int bfs(int start, int n){
    vector<int> dist(n+1,INF);
    queue<int> q;
    q.push(start);
    dist[start]=0;
    int sum = 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto next:v[curr]){
            if(dist[next]==INF){
                q.push(next);
                dist[next] = dist[curr]+1;
                sum+=dist[next];
            }
        }
    }
    return sum;
}

int main()
{
    int n,m;
    cin>>n>>m;
    v.resize(n+1);
    for(int i=0;i<m;i++){
        int n1,n2;
        cin>>n1>>n2;
        v[n1].push_back(n2);
        v[n2].push_back(n1);
    }
    int min = INF, idx = 0;
    for(int i=1;i<=n;i++){
        int sum = bfs(i,n);
        if(min>sum){
            min = sum;idx=i;
        }
    }
    printf("%d\n",idx);
    return 0;
}