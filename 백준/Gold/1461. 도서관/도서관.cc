#include <iostream>
#include <queue>

using namespace std;

int n,m,time;
priority_queue<int> positive;
priority_queue<int> negative;

void positivepop(){
    while(!positive.empty()){
        time += positive.top()<<1;
        for(int i=0;i<m;i++){
            if(positive.empty())break;
            positive.pop();
        }
    }
}

void negativepop(){
    while(!negative.empty()){
        time += negative.top()<<1;
        for(int i=0;i<m;i++){
            if(negative.empty())break;
            negative.pop();
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        if(num<0)
            negative.push(abs(num));
        else
            positive.push(num);
    }
    int maxt = 0;
    if(positive.size()==0) maxt = negative.top();
    else if(negative.size()==0) maxt = positive.top();
    else
        maxt = positive.top() > negative.top() ? positive.top() : negative.top();
    positivepop();
    negativepop();
    time -= maxt;
    printf("%d\n",time);
    return 0;
}