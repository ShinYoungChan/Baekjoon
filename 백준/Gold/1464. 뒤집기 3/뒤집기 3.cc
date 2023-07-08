#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(void){
	string s;
	cin>>s;
	list<char> li;
	li.push_back(s[0]);
	for(int i=1;i<s.length();i++){
		if(li.front()>=s[i])
			li.push_front(s[i]);
		else
			li.push_back(s[i]);
	}
	for(auto l:li)
		printf("%c",l);
	printf("\n");
	return 0;
}