#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string str;
    int t = 1;
    while(true){
        cin>>str;
        if(str[0]=='-')break;
        stack<char> s;
        int cnt = 0;
        for(unsigned int i=0;i<str.size();i++){
            if(str[i]=='{'){
                s.push(str[i]);
            }
            else{
                if(s.size()>0)
                    s.pop();
                else
                    cnt++;
            }
        }
        cnt = cnt/2+cnt%2+s.size()/2 + s.size()%2;
        printf("%d. %d\n",t,cnt);
        t++;
    }
    return 0;
}