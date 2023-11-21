#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

string decToBinary(long long num){
    string str = "";
    while(num!=0){
        str+=to_string(num%2);
        num >>= 1;
    }
    int length = str.size(), powN = 1;
    while(pow(2,powN)-1<length){
        powN++;
    }
    for(int i=0;i<pow(2,powN)-length-1;i++){
        str+="0";
    }
    reverse(str.begin(),str.end());
    return str;
}

bool checkOne(string str){
    for(int i=0;i<str.size();i++){
        if(str[i]=='1') return true;
    }
    return false;
}

bool binaryTree(string str){
    if(str.size()==1)return true;
    int len = str.size()/2;
    string left = str.substr(0,len);
    string right = str.substr(len+1,str.size());
    if(str[len]=='0'){
        if(checkOne(left)||checkOne(right)) return false;
        return true;
    }
    
    return binaryTree(left) && binaryTree(right);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer(numbers.size(), 0);
    for(int i=0;i<numbers.size();i++){
        if(binaryTree(decToBinary(numbers[i]))){
            answer[i]=1;
        }
    }
    return answer;
}