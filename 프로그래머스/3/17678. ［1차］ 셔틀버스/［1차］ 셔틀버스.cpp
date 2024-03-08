#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<pair<string,int>> bus;
    sort(timetable.begin(),timetable.end());
    int hour = 9;
    int minute = 0;
    for(int i=0;i<n;i++){
        string time = "";
        if(hour<10)
            time+="0";
        time+=to_string(hour);
        time+=":";
        if(minute<10)
            time+="0";
        time+=to_string(minute);
        
        minute+=t;
        if(minute>=60){
            minute-=60;
            hour+=1;
        }
        bus.push_back({time,m});
    }
    map<string,string> makchar;
    for(int i=0;i<bus.size();i++){
        for(int j=0;j<timetable.size();j++){
            if(bus[i].second==0)
                break;
            if(bus[i].first>=timetable[j]){
                bus[i].second--;
                makchar[bus[i].first]=timetable[j];
                timetable[j].replace(0,timetable[j].size(),"24:00");
            }
        }
    }
    int length = bus.size()-1;
    if(bus[length].second>0){
        cout<<bus[length].first<<" "<<bus[length].second<<endl;
        return bus[length].first;
    }
    hour = stoi(makchar[bus[length].first].substr(0,2));
    minute = stoi(makchar[bus[length].first].substr(3,2))-1;
    if(minute<0){
        hour-=1;
        minute=59;
    }
    if(hour<10)
        answer+="0";
    answer+=to_string(hour);
    answer+=":";
    if(minute<10)
        answer+="0";
    answer+=to_string(minute);
    return answer;
}