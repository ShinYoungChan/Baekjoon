#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    long long int b,c;
    long long int answer = n;
    cin>>b>>c;
    for(int i=0;i<n;i++){
        v[i]-=b;
        if(v[i]<=0)continue;
        answer += v[i]/c;
        if(v[i]%c>0)
            answer++;
    }
    cout<<answer<<endl;
    return 0;
}