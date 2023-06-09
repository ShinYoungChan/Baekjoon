#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    string num;
    cin>>num;
    stack<char> s;
    int start = 0;
    for(unsigned int i=0;i<num.size();i++,start++){
        if(k==0)break;
        if(s.empty()){
            s.push(num[i]);
        }
        else{
            while(!s.empty()&&k>0&&s.top()<num[i]){
                k--;
                s.pop();
            }
            s.push(num[i]);
        }
    }
    string a="";
    for(int i=num.size()-1;i>=start;i--)
        a+=num[i];
    while(!s.empty()){
        a+=s.top();
        s.pop();
    }
    for(int i=a.size()-1;i>=0+k;i--){
        printf("%c",a[i]);
    }
    return 0;
}