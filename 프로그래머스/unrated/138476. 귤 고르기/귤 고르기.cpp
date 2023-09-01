#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

bool cmp(const pair<int,int> a, const pair<int,int> b){
    if(a.second==b.second) return a.first < b.first;
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map<int,int> m;
    for(int i=0;i<tangerine.size();i++){
        m[tangerine[i]]++;
    }
    vector<pair<int,int>> v(m.begin(),m.end());
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++){
        answer++;
        if(v[i].second>=k) break;
        k-=v[i].second;
    }
    return answer;
}