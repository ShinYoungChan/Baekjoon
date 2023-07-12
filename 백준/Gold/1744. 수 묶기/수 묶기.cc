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
    int sum = 0;
    for(unsigned int i=0;i<v.size();i++){
        if(v[i]>0&&v[i+1]>0){
            if(v[i]*v[i+1]>v[i]+v[i+1]){
                sum+=v[i]*v[i+1];
                i++;
                continue;
            }
            else
                sum+=v[i];
        }
        else if(v[i]>0&&v[i+1]<=0){
            sum+=v[i];
        }
        if(v[i]==0&&(v.size()-i-1)&1){
            i++;
            continue;
        }
        if(v[i]<0&&(v.size()-i)&1){
            sum+=v[i];
        }
        else if(v[i]<0&&((v.size()-i)&1)==0){
            sum+=v[i]*v[i+1];
            i++;
        }
    }
    printf("%d\n",sum);
    return 0;
}