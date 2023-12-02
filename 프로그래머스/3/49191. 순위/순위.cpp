#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[100];
vector<pair<int,int>> v1;
bool check[100];

void bfs(int start){
    queue<int> q;
    q.push(start);
    check[start] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto next:v[curr]){
            if(!check[next]){
                check[next] = true;
                q.push(next);
                v1[start].first++;
                v1[next].second++;
            }
        }
    }
}

void reset(){
    for(int i=0;i<100;i++)
        check[i]=false;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    v1.resize(n,{0,0});
    for(auto r:results){
        v[r[0]-1].push_back(r[1]-1);
    }
    for(int i=0;i<n;i++){
        bfs(i);
        reset();
    }
    for(int i=0;i<n;i++){
        if(v1[i].first+v1[i].second==n-1)
            answer++;
    }
    return answer;
}