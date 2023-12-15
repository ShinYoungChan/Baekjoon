#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = computers.size();
    queue<int> q;
    bool check[200]={false};
    for(int i=0;i<computers.size();i++){
        q.push(i);
        check[i]=true;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int next=0;next<computers[curr].size();next++){
                if(computers[curr][next]==1 && !check[next]){
                    q.push(next);
                    check[next]=true;
                    answer--;
                }
            }
        }
    }
    return answer;
}