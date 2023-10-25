#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(vector<int> a, vector<int> b){
    if((a[0]-a[1])>(b[0]-b[1]))
        return true;
    return a[0]>b[0];
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    int oriK=k;
    sort(dungeons.begin(),dungeons.end());
    do
	{
        int ans = 0;
        for(int i=0;i<dungeons.size();i++){
          if(k >= dungeons[i][0]){
                k-=dungeons[i][1];
                ans++;
            }
        }
        k = oriK;
        if(ans>answer)
            answer=ans;

	}while(next_permutation(dungeons.begin(),dungeons.end()));   
    return answer;
}