#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string,int> in;
    map<string,int> out;
    for(auto r:records){
        int time = stoi(r.substr(0,2))*60+stoi(r.substr(3,2));
        string number = r.substr(6,4);
        string state = r.substr(11,3);
        if(state == "IN"){
            in.insert({number,time});
        }
        else{
            out[number] += (time-in[number]);
            in.erase(number);
        }
    }
    //출차 기록이 없는 경우
    for(auto x:in)
        out[x.first]+=(23*60+59-x.second);
    
    for(auto x:out){
        if(x.second<=fees[0])
            answer.push_back(fees[1]);
        else
            answer.push_back(fees[1]+ceil((x.second-fees[0])/(double)fees[2])*fees[3]);
    }
    return answer;
}