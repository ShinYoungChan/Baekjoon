#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    cin>>str;
    sort(str.begin(),str.end());
    bool flag = true;
    int ans = 0;
    do{
        flag =  true;
        for(int i=0;i<str.size()-1;i++){
            if(str[i]==str[i+1]){
                flag=false;break;
            }
        }
        if(flag) ans++;
    }while(next_permutation(str.begin(),str.end()));
    printf("%d\n",ans);
    return 0;
}