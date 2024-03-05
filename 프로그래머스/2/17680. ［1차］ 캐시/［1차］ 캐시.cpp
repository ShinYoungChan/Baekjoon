#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> v;
    if(cacheSize==0)
        return cities.size()*5;
    for(int i=0;i<cities.size();i++){
        for(int j=0;j<cities[i].size();j++)
            cities[i][j]=toupper(cities[i][j]);
        auto finded = find(v.begin(),v.end(),cities[i]);
        int asd = finded-v.begin();
        if(finded==v.end()&&v.size()<cacheSize){
            v.push_back(cities[i]);
            answer+=5;
        }
        else if(finded==v.end()&&v.size()>=cacheSize){
            v.erase(v.begin());
            v.push_back(cities[i]);
            answer+=5;
        }
        else if(finded!=v.end()){
            v.erase(v.begin()+asd);
            v.push_back(cities[i]);
            answer+=1;
        }
    }
    return answer;
}