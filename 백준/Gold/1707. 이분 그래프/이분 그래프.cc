#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> vec[20001];
int rb[20001];

bool check(int i){
	for(auto next: vec[i]){
		if(rb[i]==rb[next]){
			return false;
		}
	}
	return true;
}

int main(void){
	int test;
	scanf("%d",&test);
	while(test--){
		queue<pair<int,int>> q;
		int v,e;
		scanf("%d %d",&v,&e);
		for(int i=0;i<e;i++){
			int n1,n2;
			scanf("%d %d",&n1,&n2);
			vec[n1].push_back(n2);
			vec[n2].push_back(n1);
		}
		for(int i=1;i<=v;i++){
			if(rb[i]==0){
				q.push({i,1});
				rb[i] = 1;
			}
			while(!q.empty()){
				int curr = q.front().first;
				int c = q.front().second;
				q.pop();
				for(auto next:vec[curr]){
					if(rb[next]==0){
						rb[next] = c == 1 ? 2 : 1;
						q.push({next,rb[next]});
					}
				}
			}
		}
		bool flag = true;
		for(int i=1;i<=v;i++){
			if(!check(i)){
				flag=false;
				break;
			}
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");	
		for(int i=0;i<=v;i++){
			vec[i].clear();
			rb[i] = 0;
		}
	}
	return 0 ;
}