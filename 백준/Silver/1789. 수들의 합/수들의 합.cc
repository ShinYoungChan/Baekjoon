#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin>>n;
    long long sum=0;
    long long ans=0;
    for(long long i=1;;i++){
        if(sum>n){
            break;
        }
        sum+=i;
        ans++;
    }
    printf("%lld\n",ans-1);
    return 0;
}