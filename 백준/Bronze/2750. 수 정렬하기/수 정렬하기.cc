#include <stdio.h>
#include <stdlib.h>

int main(){
    int number;
    scanf("%d",&number);
    
    int *num=(int*)malloc(sizeof(int)*number);
    
    for(int i=0;i<number;i++)
    	scanf("%d",&num[i]);
    	
	for(int i=0;i<number;i++){
		for(int j=i;j<number;j++)
		if(num[i]>num[j]){
			int tmp=num[i];
			num[i]=num[j];
			num[j]=tmp;
		}
	}
    for(int i=0;i<number;i++)
    	printf("%d\n",num[i]);
}