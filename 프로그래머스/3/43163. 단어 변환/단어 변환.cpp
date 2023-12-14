#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

bool wordcount(string str1, string str2){
    int cnt = 0;
    for(int i=0;i<str1.size();i++){
        if(str1[i]!=str2[i])
            cnt++;
        if(cnt>1)
            return false;
    }
    return true;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 2100000000;
    unordered_set<string> us;
    queue<pair<string, int>> q;
    q.push({begin, 0});
    while(!q.empty()){
        string curr = q.front().first;
        int cnt = q.front().second;
        if(curr==target){
            answer=cnt;
            break;
        }
        q.pop();
        for(int i=0;i<words.size();i++){
            if(us.count(words[i])==0 && wordcount(curr,words[i])){
                q.push({words[i],cnt+1});
                us.insert(words[i]);
            }
        }
    }
    return answer==2100000000 ? 0:answer;
}