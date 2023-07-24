#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    long long int ans = 0;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        ans += abs(i-v[i]+1);
    }
    cout<<ans<<"\n";
    return 0;
}