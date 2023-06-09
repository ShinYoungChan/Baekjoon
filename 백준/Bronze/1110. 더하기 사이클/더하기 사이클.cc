#include <stdio.h>

int main(void){
    int n,count=0;
    int sum1,sum;
    scanf("%d",&n);
    sum=n;
    while(1){
        sum1= sum / 10 + sum % 10;
        if(sum1<10)
            sum= (sum % 10) * 10 + sum1;
        else
            sum=(sum % 10) * 10 + sum1 % 10;
        count++;
        if(sum==n)
            break;
    }
    printf("%d",count);
    return 0;
}