#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    queue<int> q;
    vector<int> a[20001];
    int dist[20001];
    for(int i=0;i<20001;i++)
        dist[i]=50001;
    for(int i=0;i<edge.size();i++){
        int n1 = edge[i][0];
        int n2 = edge[i][1];
        a[n1].push_back(n2);
        a[n2].push_back(n1);
    }
    q.push(1);
    dist[1]=0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto next:a[curr]){
            if(dist[next]>dist[curr]+1){
                dist[next]=dist[curr]+1;
                q.push(next);
            }
        }
    }
    int max=0;
    for(int i=2;i<n+1;i++){
        if(max==dist[i])
            answer++;
        if(max<dist[i]){
            max=dist[i];
            answer = 1;
        }
    }
    return answer;
}