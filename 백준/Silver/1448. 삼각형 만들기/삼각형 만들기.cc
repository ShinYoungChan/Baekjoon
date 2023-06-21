#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	int n;
	scanf("%d",&n);
	vector<int> v;
	for(int i=0;i<n;i++){
		int num;
		scanf("%d",&num);
		v.push_back(num);
	}
	sort(v.begin(),v.end());
	int sum = 0;
	for(int i=v.size()-1;i>=2;i--){
		if(v[i]<v[i-1]+v[i-2]){
			sum = v[i]+v[i-1]+v[i-2];
			break;
		}
	}
	if(sum==0)
		printf("-1\n");
	else
		printf("%d\n",sum);
	return 0;
}