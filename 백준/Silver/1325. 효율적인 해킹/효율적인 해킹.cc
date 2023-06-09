#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a[10001];

int main(void) {
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int n1,n2;
        scanf("%d %d",&n1,&n2);
        a[n2].push_back(n1);
    }
    vector<int> num;
    int maxCount = 0;
    bool *check = new bool[n+1];
    for(int i=1;i<=n;i++){
        queue<int> q;
        q.push(i);
        int count = 1;
        for(int j=1;j<n+1;j++){
            check[j]=false;
        }
        check[i]=true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto next:a[curr]){
                if(!check[next]){
                    q.push(next);
                    check[next]=true;
                    count++;
                }
            }
        }
        if(maxCount==count){
            num.push_back(i);
        }
        else if(maxCount<count){
            maxCount=count;
            num.clear();
            num.push_back(i);
        }
    }
    sort(num.begin(),num.end());
    for(int i=0;i<num.size();i++)
        printf("%d ",num[i]);
	return 0;
}