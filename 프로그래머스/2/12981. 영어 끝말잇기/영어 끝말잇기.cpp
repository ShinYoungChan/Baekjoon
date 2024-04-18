#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2);
    vector<string> str;
    int num=0;
    int order=0;
    for(int i=1;i<words.size();i++){
        str.push_back(words[i-1]);
        num=i%n;
        order=i/n;
        if(words[i-1].back()!=words[i][0]||find(str.begin(),str.end(),words[i])!=str.end()){
            answer[0]=num+1;
            answer[1]=order+1;
            return answer;
        }
    }
    return answer;
}