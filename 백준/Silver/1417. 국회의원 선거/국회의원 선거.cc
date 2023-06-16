#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(i>0)pq.push(v[i]);
    }
    int answer = 0;
    while(pq.size()>0&&v[0]<=pq.top()){
        int num = pq.top();pq.pop();
        answer++;v[0]++;
        pq.push(num-1);
    }
    printf("%d\n",answer);
    return 0;
}