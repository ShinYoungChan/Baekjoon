#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
#define MAX_D 50001
#define INF 2100000000

using namespace std;

vector<pair<int,int>> v[MAX_D];
unordered_set<int> summit;
unordered_set<int> info;
int dist[MAX_D];

void bfs(vector<int> gates){
    for(auto g:gates)
        info.insert(g);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i=0;i<MAX_D;i++){
        dist[i]=INF;
        if(info.count(i)){
            pq.push({0,i});
            dist[i]=0;
        }
    }
    while(!pq.empty()){
        int distance = pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        if(dist[curr]<distance)continue;
        if(summit.count(curr))continue;
        for(auto next:v[curr]){
            if(info.count(next.first))continue;
            int nextP = next.first;
            int cost = next.second > distance ? next.second:distance;
            if(dist[nextP]>cost){
                dist[nextP]=cost;
                pq.push({cost,nextP});
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer(2);
    for(auto p:paths){
        v[p[0]].push_back({p[1],p[2]});
        v[p[1]].push_back({p[0],p[2]});   
    }
    for(auto s:summits)
        summit.insert(s);
    bfs(gates);
    sort(summits.begin(),summits.end());
    answer[1]=INF;
    for(auto s:summits){
        if(answer[1]>dist[s]){
            answer[1]=dist[s];
            answer[0]=s;
        }
    }
    return answer;
}