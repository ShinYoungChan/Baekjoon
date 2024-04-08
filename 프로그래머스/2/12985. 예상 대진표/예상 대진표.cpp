#include <iostream>
#include <math.h>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    
    while(true){
        answer++;
        if(abs(a-b)==1&&a/2!=b/2)
            break;
        a=a%2==0?a/2:a/2+1;
        b=b%2==0?b/2:b/2+1;
    }

    return answer;
}