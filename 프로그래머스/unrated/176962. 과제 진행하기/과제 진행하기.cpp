#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

struct plan{
    string name;
    int time, play;
};

bool operator < (plan a, plan b){
        return a.time > b.time;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    priority_queue<plan> pq;
    for(int i=0;i<plans.size();i++){
        int hour = stoi(plans[i][1].substr(0,plans[i][1].find(":")));
        int minute = stoi(plans[i][1].substr(plans[i][1].find(":")+1,2));
        int time = hour*60+minute;
        int playtime = stoi(plans[i][2]);
        plan p;
        p.name = plans[i][0], p.time = time, p.play = playtime;
        pq.push(p);
    }
    stack<plan> s;
    int ctime = 0;
    while(!pq.empty()){
        plan curr = pq.top();
        //대기 작업이 있는 경우
        if(s.size()>0){
            plan asd = s.top();s.pop();
            asd.time=ctime;
            //대기 작업이 다음 작업보다 시간이 빠른경우
            if(ctime<curr.time){
                pq.push(asd);
                continue;
            }
            else{
                s.push(asd);
            }
        }
        pq.pop();
        ctime = curr.time+curr.play;
        plan next = pq.top();
        //현재 하고 있는 작업이 다음 작업 시간보다 빨리 끝나는 경우
        if(ctime <= next.time){
            answer.push_back(curr.name);
        }
        else{
            curr.play = curr.play - (next.time-curr.time);
            ctime=next.time;
            s.push(curr);
        }
    }
    while(!s.empty()){
        answer.push_back(s.top().name);
        s.pop();
    }
    return answer;
}