#include <iostream>
#include <cmath>

using namespace std;

void dfs(int n){
    if(n==0){
        printf("-");
        return;
    }
    dfs(n-1);
    for(int i=0;i<pow(3,n-1);i++){
        printf(" ");
    }
    dfs(n-1);
}

int main()
{
    int n;
    while(cin>>n){
        dfs(n);
        printf("\n");
    }

    return 0;
}