#include <iostream>

using namespace std;

int gcd(long long a, long long b){
    if(a<b){
        long long tmp = a;
        a = b;
        b = tmp;
    }
    long long mod;
    while(b!=0){
        mod = a%b;
        a=b;
        b=mod;
    }
    return a;
}

int main()
{
    long long g,l;
    cin>>g>>l;
    int ans[2] = {0,0};
    int diff=2100000000;
    
    for(int i=g;i<=l;i++){
        long long mul = g*l;
        if(mul%i==0){
            long long div = mul/i;
            if(gcd(i,div)!=g) continue;
            if(diff>div+i){
                ans[0]=i;ans[1]=div;
                diff=div+i;
            }
        }
    }
    printf("%d %d\n",ans[0],ans[1]);
    return 0;
}