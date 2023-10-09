#include <string>
#include <vector>
#include <iostream>

using namespace std;

unsigned long long int qSum1 = 0;
unsigned long long int qSum2 = 0;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    for(int i=0;i<queue1.size();i++)
        qSum1 += queue1[i];
    for(int i=0;i<queue2.size();i++)
        qSum2 += queue2[i];
    
    int qCount1 = 0;
    int qCount2 = 0;
    int size = (queue1.size()+queue2.size()) * 2;
    while(answer<=size && qSum1!=qSum2){
        if(qSum1<qSum2){
            qSum1 += queue2[qCount2];
            qSum2 -= queue2[qCount2];
            queue1.push_back(queue2[qCount2++]);
            answer++;
        }
        if(qSum1>qSum2){
            qSum1 -= queue1[qCount1];
            qSum2 += queue1[qCount1];
            queue2.push_back(queue1[qCount1++]);
            answer++;
        }
    }
    cout<<qSum1<<" "<<qSum2<<endl;
    return qSum1==qSum2 ? answer : -1;
}