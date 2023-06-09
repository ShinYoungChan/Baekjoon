#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<string>v(n);
    vector<int> alpha(26,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        int cal = 1;
        for(int j=v[i].size()-1;j>=0;j--){
            alpha[v[i][j]-'A'] += cal;
            cal*=10;
        }
    }
    sort(alpha.begin(),alpha.end(),greater<int>());
    int sum = 0;
    for(int i=0;i<alpha.size();i++){
        sum+=alpha[i]*(9-i);
    }
    printf("%d\n",sum);
    return 0;
}