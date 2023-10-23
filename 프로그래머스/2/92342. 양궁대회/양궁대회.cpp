#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> answer(1,-1);
vector<int> apeach(11,0);
vector<int> rion(11,0);
int maxScore = 0;

void dfs(int index, int n){
    if(n<=0||index>rion.size()-1){
        if(n>=0)
            rion[rion.size()-1] = n;
        int rsum = 0;
        int asum = 0;
        for(int i=0;i<rion.size();i++){
            if(rion[i] > apeach[i])
                rsum += 10 - i;
            else if(rion[i] < apeach[i])
                asum += 10 - i;
        }
        if(maxScore < rsum - asum){
            answer = rion;
            maxScore = rsum - asum;
        }
        else if(maxScore == rsum - asum){
            for(int i=rion.size()-1;i>=0;i--){
                if(answer[i]>rion[i])break;
                if(rion[i] > answer[i]){
                    answer = rion;
                    break;
                }
            }
        }
        return;
    }
    //남은 화살 수 > 어피치가 맞춘 화살 수
    if(n > apeach[index]){
        rion[index] = apeach[index] + 1;
        dfs(index+1,n-rion[index]);
    }
    rion[index] = 0;
    dfs(index+1,n);
}

vector<int> solution(int n, vector<int> info) {
    for(int i=0;i<info.size();i++)
        apeach[i]=info[i];
    dfs(0,n);
    return answer;
}