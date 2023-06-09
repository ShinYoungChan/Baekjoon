#include <iostream>

using namespace std;

bool ban[10];
int minClick;
int channel;

void dfs(int num, int cnt){
    if(cnt>6)return;
    int qqq = abs(num-channel);
    if(minClick>cnt+qqq){
        minClick=cnt+qqq;
    }
    for(int i=0;i<10;i++){
        if(!ban[i]){
            dfs(num*10+i,cnt+1);
        }
    }
}

int main()
{
    cin>>channel;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        ban[num]=true;
    }
    minClick=abs(channel-100);
    for(int i=0;i<10;i++){
        if(!ban[i]){
            dfs(i,1);
        }
    }
    printf("%d\n",minClick);
    return 0;
}