#include <iostream>
#include <queue>

using namespace std;

int main(void){
	int n;
	scanf("%d",&n);
	priority_queue<int> maxheap;
	priority_queue<int, vector<int>, greater<int>> minheap;
	for(int i=0;i<n;i++){
		int num;
		scanf("%d",&num);
		if(maxheap.size()==0){
			maxheap.push(num);
		}
		else{
			if(maxheap.size()>minheap.size()){
				minheap.push(num);
			}
			else{
				maxheap.push(num);
			}
			if(maxheap.top()>minheap.top()){
				int max = maxheap.top();
				int min = minheap.top();
				maxheap.pop();
				minheap.pop();
				maxheap.push(min);
				minheap.push(max);
			}
		}
		printf("%d\n",maxheap.top());
	}
    return 0;
}