#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <limits>

using namespace std;

vector<pair<int,int>> v[201];
int dist[201];

int dijkstra(int start,int end,int n){
    for(int i=1;i<n+1;i++){
        dist[i]=100000*n+1;
    }
    priority_queue<pair<int,int>> q;
    q.push({0,start});
    dist[start] = 0;
    while(!q.empty()){
        int cost = -q.top().first;
        int curr = q.top().second;
        if(curr==end)
            break;
        q.pop();
        for(auto next: v[curr]){
            if(dist[next.first]>dist[curr]+next.second){
                dist[next.first] = dist[curr]+next.second;
                q.push({-next.second,next.first});
            }
        }
    }
    return dist[end];
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int d[201][201];
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(i==j)
                d[i][j]=0;
            else
                d[i][j]=100000*n+1;
        }
    }
    
    for(int i = 0; i<fares.size();i++){
        int n1 = fares[i][0];
        int n2 = fares[i][1];
        int cost = fares[i][2];
        d[n1][n2] = cost;
        d[n2][n1] = cost;
    }
    for(int k=1;k<n+1;k++){
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(d[i][j]>d[i][k]+d[k][j])
                    d[i][j]=d[i][k]+d[k][j];
            }
        }
    }
    int answer = d[s][a] + d[s][b];
    for(int i=1;i<n+1;i++){
        int cost = d[s][i] + d[i][a] + d[i][b];
        answer = answer < cost ? answer : cost;
    }
    return answer;
}