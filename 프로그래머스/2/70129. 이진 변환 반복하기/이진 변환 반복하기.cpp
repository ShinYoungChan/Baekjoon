#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int transCount=0;
    int zeroCount = 0;
    while(s.length()!=1){
        zeroCount+=count(s.begin(),s.end(),'0');
        transCount++;
        s.erase(remove(s.begin(),s.end(),'0'),s.end());
        int len=s.length();
        string s1="";
        while(len){
            s1+=to_string(len%2);
            len/=2;
        }
        reverse(s1.begin(),s1.end());
        s=s1;
    }
    answer.push_back(transCount);
    answer.push_back(zeroCount);
    return answer;
}