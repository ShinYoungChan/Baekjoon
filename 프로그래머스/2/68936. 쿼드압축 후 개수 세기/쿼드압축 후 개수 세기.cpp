#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> answer[2];
int count[2];

void quadtree(int n, int x, int y,const vector<vector<int>>&arr){
    bool zero = true;
    bool one = true;
    
    for(int i=x;i<x+n;i++){
        for(int j=y;j<y+n;j++){
            if(arr[i][j]==1)
                zero = false;
            else
                one = false;
            if(!zero && !one)
                break;
        }
        if(!zero && !one)
                break;
    }
    if(zero){
        // answer[0].push_back(0);
        count[0]+=1;
    }
    else if(one){
        // answer[1].push_back(1);
        count[1]+=1;
    }
    else{
        quadtree(n/2,x,y,arr);
        quadtree(n/2,x,y+n/2,arr);
        quadtree(n/2,x+n/2,y,arr);
        quadtree(n/2,x+n/2,y+n/2,arr);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    int n = arr.size();
    quadtree(n, 0, 0, arr);
    vector<int> a;
    for(int i=0;i<2;i++){
        a.push_back(count[i]);
        // a.push_back(answer[i].size());
    }
    return a;
}