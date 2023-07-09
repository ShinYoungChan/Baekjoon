#include <stdio.h>
#include <stdlib.h>

int main(){
    int number,max;
    scanf("%d",&number);
    
    int *grade=(int*)malloc(sizeof(int)*number);
    
    for(int i=0; i<number;i++)
    	scanf("%d",&grade[i]);
    	
    max=grade[0];
    
    for(int i=1; i<number;i++)
    	if(max<grade[i])
    		max=grade[i];
   
   double sum=0.0;
   for(int i=0;i<number;i++)
   		sum+=((double)grade[i]/max)*100;
   	
   	printf("%f",sum/number);
}