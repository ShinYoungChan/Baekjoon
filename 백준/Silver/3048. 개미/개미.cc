#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n1,n2,t;
    cin>>n1>>n2;
    string str1, str2;
    cin>>str1>>str2;
    cin>>t;
    reverse(str1.begin(),str1.end());
    vector<pair<char,int>> v;
    for(int i=0;i<n1;i++){
        v.push_back(make_pair(str1[i],0));
    }
    for(int i=0;i<n2;i++){
        v.push_back(make_pair(str2[i],1));
    }
    for(int i=0;i<t;i++){
        for(int j=0;j<n1+n2-1;j++){
            if(v[j].second==0&&v[j+1].second==1){
                swap(v[j],v[j+1]);
                j++;
            }
        }
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i].first;
    }
    return 0;
}