#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    for(int i=0,j = 0;i<A.size();){
        if(j==A.size())break;
        if(A[i]<B[j]){
            i++;
            j++;
            answer++;
        }
        else
            j++;
    }
    return answer;
}