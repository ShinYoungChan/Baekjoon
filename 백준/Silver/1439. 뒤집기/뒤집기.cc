#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin>>str;
    int zCnt = 0, oCnt = 0;
    char ch = str[0];
    ch == '0' ? zCnt++:oCnt++;
    for(unsigned int i=1;i<str.size();i++){
        if(str[i-1]!=str[i]&&ch=='0'){
            ch='1';
            oCnt++;
        }
        else if(str[i-1]!=str[i]&&ch=='1'){
            ch='0';
            zCnt++;
        }
    }
    printf("%d\n",zCnt<oCnt?zCnt:oCnt);
    return 0;
}