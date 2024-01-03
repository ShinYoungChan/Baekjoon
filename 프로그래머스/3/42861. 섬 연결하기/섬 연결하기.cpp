#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct node{
    int cost,n1,n2;
};

bool operator < (node node1, node node2){
    if(node1.cost==node2.cost)
        return node1.n1 > node2.n1;
    return node1.cost > node2.cost;
}

int parent[100];

int getParent(int x){
    if(parent[x]==x)return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a<b)parent[b]=a;
    else parent[a]=b;
}

bool find(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a==b)return true;
    return false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    priority_queue<node> pq;
    for(int i=0;i<costs.size();i++){
        int n1 = costs[i][0];
        int n2 = costs[i][1];
        int cost = costs[i][2];
        node nd;
        nd.cost = cost, nd.n1 = n1, nd.n2 = n2;
        pq.push(nd);
    }
    while(!pq.empty()){
        node nd = pq.top();pq.pop();
        if(!find(nd.n1,nd.n2)){
            answer+=nd.cost;
            unionParent(nd.n1,nd.n2);
        }
    }
    return answer;
}