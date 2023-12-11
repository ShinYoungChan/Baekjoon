#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, vector<string>> um;
unordered_map<string, vector<bool>> check;
string str="Z";
int tsize = 0;

void dfs(string s, string st, int cnt){
    if(cnt==tsize){
        if(str>st)
            str=st;
        return;
    }
    for(int i=0;i<um[s].size();i++){
        if(!check[s][i]){
            check[s][i]=true;
            dfs(um[s][i],st+um[s][i],cnt+1);
            check[s][i]=false;
        }
    }
    return;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    tsize = tickets.size();
    for(auto t:tickets){
        um[t[0]].push_back(t[1]);
        check[t[0]].push_back(false);
    }
    // for(auto it=um.begin();it!=um.end();it++){
    //     sort(it->second.begin(),it->second.end());
    // }
    dfs("ICN","ICN",0);
    for(int i=0;i<str.size();i+=3){
        answer.push_back(str.substr(i,3));
    }
    return answer;
}