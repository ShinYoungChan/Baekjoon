#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    vector<int> v1(sequence.size(),0);
    vector<int> v2(sequence.size(),0);
    for(int i=0;i<v1.size();i++){
        v1[i] = i&1==1? sequence[i] : -sequence[i];
        v2[i] = i&1==1? -sequence[i] : sequence[i];
    }
    long long ans1 = 0;
    long long ans2 = 0;
    for(int i=0;i<v1.size();i++){
        ans1+=v1[i];
        ans2+=v2[i];
        if(ans1<0)ans1=0;
        if(ans2<0)ans2=0;
        if(answer<ans1)answer=ans1;
        if(answer<ans2)answer=ans2;
    }
    return answer;
}