#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    unordered_set<int> s1;
    unordered_set<int> s2(topping.begin(),topping.end());
    unordered_map<int,int> m;
    for(int i=0;i<topping.size();i++){
        m[topping[i]]++;
    }
    for(int i=0;i<topping.size();i++){
        m[topping[i]]--;
        if(m[topping[i]]==0)s2.erase(topping[i]);
        s1.insert(topping[i]);
        if(s1.size()==s2.size())answer++;
    }
    return answer;
}