#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> maxQ;
    // priority_queue<int, vector<int>, greater<int>> minQ;
    for(auto oper:operations){
        char com = oper[0];
        string num = oper.substr(2,oper.size());
        if(com=='I'){
            maxQ.push(stoi(num));
            // minQ.push(stoi(num));
        }
        else{
            if(maxQ.empty())
                continue;
            if(num == "1"){
                maxQ.pop();
            }
            else if(num=="-1"){
                priority_queue<int, vector<int>, greater<int>> minQ;
                while(!maxQ.empty()){
                    minQ.push(maxQ.top());
                    maxQ.pop();
                }
                minQ.pop();
                while(!minQ.empty()){
                    maxQ.push(minQ.top());
                    minQ.pop();
                }
            }
        }
    }
    if(maxQ.empty()){
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }
    int max = maxQ.top();
    int min;
    while(!maxQ.empty()){
        min=maxQ.top();
        maxQ.pop();
    }
    answer.push_back(max);
    answer.push_back(min);
    return answer;
}