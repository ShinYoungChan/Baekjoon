#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> v[100001];

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer(sources.size(),-1);
    vector<int> dist(n+1,100001);
    for(int i=0;i<roads.size();i++){
        v[roads[i][0]].push_back(roads[i][1]);
        v[roads[i][1]].push_back(roads[i][0]);
    }
    queue<int> q;
    q.push(destination);
    dist[destination] = 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto next:v[curr]){
            if(dist[next]>dist[curr]+1){
                dist[next] = dist[curr]+1;
                q.push(next);
            }
        }
    }
    for(int i=0;i<sources.size();i++){
        if(dist[sources[i]]==100001)continue;
        answer[i]=dist[sources[i]];
    }
    return answer;
}