#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int answer = 0;
    for(int i=v.size()-1;i>0;i--){
        if(v[i]<=v[i-1]){
            answer += (v[i-1]-v[i]+1);
            v[i-1]=v[i]-1;
        }
    }
    printf("%d\n",answer);
    return 0;
}