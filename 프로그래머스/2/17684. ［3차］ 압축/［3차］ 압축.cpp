#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> word;
    for(char i = 'A'; i<='Z';i++){
        string str = "";
        str += i;
        word[str] = i-'A' + 1;
    }
    int wordCnt = 27;
    int len = 1;
    string str(1,msg[0]);
    for(int i=1;i<msg.size();i++){
        str+=msg[i];
        // 현재 단어가 등록 안된 경우
        if(word[str]==0){
            answer.push_back(word[str.substr(0,len)]);
            word[str]=wordCnt++;
            str = str.substr(len, str.size());
            len = 1;
        }
        // 현재 단어가 등록된 경우
        else {
            len++;
        }
    }
    answer.push_back(word[str]);
    return answer;
}