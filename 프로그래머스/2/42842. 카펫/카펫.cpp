#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int n = brown+yellow;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            int n1 = i;
            int n2 = n/i;
            int sum = 0;
            if(n1>=n2)
                sum = n1*2+(n2-2)*2;
            if(sum==brown){
                answer.push_back(n1);
                answer.push_back(n2);
                break;
            }
        }
    }
    return answer;
}