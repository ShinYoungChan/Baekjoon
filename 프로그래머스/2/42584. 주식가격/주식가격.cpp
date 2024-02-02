#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    queue<pair<int,int>> q;
    for(int i=0;i<prices.size()-1;i++){
        int num = 0;
        for(int j=i+1;j<prices.size();j++){
            num++;
            if(prices[i]>prices[j]){
                break;
            }
        }
        answer[i]=num;
    }
    return answer;
}