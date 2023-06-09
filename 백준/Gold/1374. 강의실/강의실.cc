#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        int a;
        cin>>a>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end());
    priority_queue<int> pq;
    pq.push(-v[0].second);
    for(unsigned int i=1;i<v.size();i++){
        pq.push(-v[i].second);
        if(-pq.top()<=v[i].first){
            pq.pop();
        }
    }
    printf("%ld\n",pq.size());
    return 0;
}