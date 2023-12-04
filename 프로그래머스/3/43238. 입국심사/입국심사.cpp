#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = times[times.size()-1]*n;
    sort(times.begin(),times.end());
    long long low = 1;
    long long high = (long long)times[times.size()-1]*n;
    while(high>=low){
        long long mid = (high+low)/2;
        long long s = 0;
        for(int i=0;i<times.size();i++){
            s+=mid/times[i];
        }
        if(s>=n){
            answer = answer < mid ? answer : mid;
            high = mid-1;
        }
        else
            low = mid+1;
    }
    return answer;
}