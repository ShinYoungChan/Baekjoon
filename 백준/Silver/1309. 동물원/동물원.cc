#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,0);
    dp[0]=1;dp[1]=3;
    for(int i=2;i<=n;i++){
        dp[i] = (dp[i-1]*2+dp[i-2])%9901;
    }
    printf("%d\n",dp[n]);
    return 0;
}