#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int oriN=n;
    int total = n;
    int sum=n*(n+1)/2;
    int ans[1000][1000]={0};
    int start = 1;
    int i,j,k;
    i=j=k=0;
    // int num[3]={0,1,2};
    int num[3][2]={{1,0},{0,1},{-1,-1}};
    while(start<sum+1){
        ans[i][j]=start;
        if(start==total){
            total+=n-1;
            n--;
            k++;
        }
        i+=num[k%3][0];
        j+=num[k%3][1];
        start++;
    }
  
    for(int i=0;i<oriN;i++){
        for(int j=0;j<oriN;j++){
            if(ans[i][j]!=0)
                answer.push_back(ans[i][j]);
        }
    }
    return answer;
}