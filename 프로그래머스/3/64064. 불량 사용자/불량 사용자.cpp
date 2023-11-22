#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

unordered_map<string,set<string>> um;
unordered_map<string,bool> wordcheck;
set<set<string>> result;

bool check(string ban, string user){
    if(ban.size()!=user.size())return false;
    for(int i=0;i<ban.size();i++){
        if(ban[i]=='*')continue;
        if(ban[i]!=user[i])return false;
    }
    return true;
}

void dfs(vector<string> banned_id, set<string> s, int idx){
    if(banned_id.size()==idx){
        result.insert(s);
        return;
    }
    for(auto word:um[banned_id[idx]]){
        if(!wordcheck[word]){
            wordcheck[word]=true;
            s.insert(word);
            dfs(banned_id,s,idx+1);
            s.erase(word);
            wordcheck[word]=false;
        }
    }
    return;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    for(int i=0;i<banned_id.size();i++){
        for(int j=0;j<user_id.size();j++){
            if(check(banned_id[i],user_id[j])){
                um[banned_id[i]].insert(user_id[j]);
            }
        }
    }
    dfs(banned_id,set<string>(),0);
    return result.size();
}