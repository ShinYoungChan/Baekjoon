#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> q;
    for(auto x: scoville)
        q.push(x);
	while(q.size()>1){
        int num[2];
        if(q.top()>=K)
            break;
        for(int i=0;i<2;i++){
            num[i]=q.top();
            q.pop();
        }
        q.push(num[0]+num[1]*2);
        answer++;
    }
    return q.top()>=K?answer:-1;
}