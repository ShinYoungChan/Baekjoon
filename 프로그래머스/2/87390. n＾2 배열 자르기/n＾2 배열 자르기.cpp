#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for(long long i=left;i<right+1;i++){
        long long x=i/n+1;
        long long y=i%n+1;
        answer.push_back(x>y?x:y);
    }
    return answer;
}