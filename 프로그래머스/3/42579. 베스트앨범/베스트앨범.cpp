#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(const pair<string,int>& a, const pair<string,int>& b) {
    if(a.second==b.second) return a.first < b.first;
	return a.second > b.second;
}

bool cmp1(const pair<int,int>& a, const pair<int,int>& b) {
    if(a.second==b.second) return a.first < b.first;
	return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> um;
    unordered_map<string, vector<pair<int,int>>> umm;
    for(int i=0;i<genres.size();i++){
        um[genres[i]]+=plays[i];
        umm[genres[i]].push_back({i, plays[i]});
    }
    vector<pair<string, int>> v(um.begin(), um.end());
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++){
        sort(umm[v[i].first].begin(),umm[v[i].first].end(),cmp1);
        for(int j=0;j<umm[v[i].first].size();j++){
            if(j==2)break;
            answer.push_back(umm[v[i].first][j].first);
        }
     
    }
    return answer;
}