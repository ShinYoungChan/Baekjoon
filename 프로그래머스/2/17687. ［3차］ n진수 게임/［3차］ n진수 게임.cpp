#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string conversion(int num, int n){
    string convert = "";
    while(num!=0){
        if(num % n < 10){
            convert+=to_string(num%n);
        }
        else {
            convert+=(char)(num % n - 10 + 'A');
        }
        num/=n;
    }
    reverse(convert.begin(),convert.end());
    return convert;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string binary = "0";
    for(int i=1;i<50000;i++){
        binary+=conversion(i,n);
    }
    for(int i=p-1,s=0;s<t;s++,i+=m){
        answer+=binary[i];
    }
    return answer;
}