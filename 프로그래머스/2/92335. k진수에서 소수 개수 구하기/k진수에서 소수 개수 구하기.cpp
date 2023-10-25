#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <iostream>

using namespace std;

bool prime(long long int num){
    if(num==1)
        return false;
    for(long long int i=2;i<=int(sqrt(num));i++)
        if(num%i==0)
            return false;
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string s = "";
    while(n){
        s+=to_string(n%k);
        n = n/k;
    }
    reverse(s.begin(),s.end());
    stringstream ss(s);
    string buffer;
    vector<long long int> v;
    while(getline(ss,buffer,'0')){
        if(buffer.length()!=0)
            v.push_back(stol(buffer));
    }
    for(auto x:v){
        if(prime(x))
            answer++;
    }
    return answer;
}