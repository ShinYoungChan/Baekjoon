#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int dp[500][500];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    dp[0][0] = triangle[0][0];
    for(int i=1;i<triangle.size();i++){
        for(int j=0;j<triangle[i].size();j++){
            if(j==0){
                dp[i][j] = dp[i-1][j] + triangle[i][j];
            }
            else if(j==triangle[i].size()-1)
                dp[i][j] = dp[i-1][j-1]+triangle[i][j];
            else{
                dp[i][j] = max(dp[i-1][j-1]+triangle[i][j],dp[i-1][j]+triangle[i][j]);
            }
            answer = max(answer,dp[i][j]);
        }
    }
    return answer;
}