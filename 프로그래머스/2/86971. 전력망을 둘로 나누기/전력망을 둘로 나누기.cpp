#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> v[101];
vector<bool> visit(101,false);
int skip = 0;

void init(int n, vector<vector<int>> &wires){
    for(int i=0;i<=n;i++){
        v[i].clear();
        visit[i]=false;
    }
    for(int i=0;i<wires.size();i++){
        // 하나 연결 안하기
        if(i==skip) continue;
        v[wires[i][0]].push_back(wires[i][1]);
        v[wires[i][1]].push_back(wires[i][0]);
    }
    skip++;
}

int bfs(int start){
    queue<int> q;
    visit[start]=true;
    q.push(start);
    int cnt = 1;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto next:v[curr]){
            if(!visit[next]){
                visit[next]=true;
                q.push(next);
                cnt++;
            }
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    int ans[2], cnt;
    for(int s=0;s<n;s++){
        ans[0] = ans[1] = cnt = 0;
        init(n, wires);
        for(int i=1;i<=n;i++){
            if(!visit[i]){
                ans[cnt] = bfs(i);
                cnt++;
            }
        }
        int diff = abs(ans[0]-ans[1]);
        if(answer>diff) answer = diff;
    }
    return answer;
}