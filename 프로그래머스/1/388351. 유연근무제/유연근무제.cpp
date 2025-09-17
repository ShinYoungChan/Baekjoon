#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    for(int i=0;i<schedules.size();i++){
        int ok = schedules[i] + 10;
        if(ok%100/10==6){
            ok+=40;
        }
        //printf("ok = %d\n",ok);
        bool flag = true;
        for(int j=0;j<timelogs[i].size();j++){
            int today = (startday + j - 1) % 7 + 1;
            if((today % 7 == 6) || (today % 7 == 0)){
                continue;
            }
            if(timelogs[i][j]>ok){
                flag=false;
                break;
            }
        }
        if(flag) answer++;
    }
    return answer;
}