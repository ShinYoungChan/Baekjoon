#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> num;
vector<int> v;
vector<bool> visit;
set<int> s;

void dfs(int target, int curr){
    if(visit[curr]){
        if(target==curr){
            s.insert(target);
        }
        return;
    }
    visit[curr]=true;
    dfs(target,v[curr]);
}

int main(){
    int n;
    cin>>n;
    num.resize(n+1);
    v.resize(n+1);
    visit.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        num[i]=i;
    }
    for(int i=1;i<=n;i++){
        visit[i]=true;
        dfs(i,v[i]);
        fill(visit.begin(),visit.end(),false);
    }
    cout<<s.size()<<"\n";
    for(auto a:s){
        cout<<a<<"\n";
    }
    return 0;
}