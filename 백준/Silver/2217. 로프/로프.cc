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
    sort(v.begin(),v.end(),greater<>());
    int answer = 0;
    for(unsigned int i=0;i<v.size();i++){
        int avg = v[i]*(i+1);
        if(answer<avg)
            answer=avg;
    }
    printf("%d\n",answer);
    return 0;
}