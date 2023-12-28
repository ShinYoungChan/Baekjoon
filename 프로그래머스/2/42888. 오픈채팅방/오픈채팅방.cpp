#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string,string>> name;
    map<string,string> map1;
    vector<string>tempName;
    for(int i=0;i<record.size();i++){
        stringstream ss(record[i]);
        string temp;
        while(getline(ss,temp,' ')){
            tempName.push_back(temp);
        }
        name.push_back({tempName[0],tempName[1]});
        if(tempName.size()==3){
            map1[tempName[1]]=tempName[2];
        }
        tempName.clear();
        
    }

    for(int i=0;i<name.size();i++){
        if(name[i].first=="Change")
            continue;
        else if(name[i].first=="Enter")
            answer.push_back(map1[name[i].second]+"님이 들어왔습니다.");
        else if(name[i].first=="Leave")
            answer.push_back(map1[name[i].second]+"님이 나갔습니다.");
    }
    return answer;
}