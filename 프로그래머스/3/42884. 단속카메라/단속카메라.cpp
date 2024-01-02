#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(),routes.end());
    int camera = routes[0][1];
    for(int i=1;i<routes.size();i++){
        if(camera<routes[i][0]){
            answer++;
            camera=routes[i][0]>routes[i][1]?routes[i][0]:routes[i][1];
        }
        else{
            camera = camera<routes[i][1]?camera:routes[i][1];
        }
    }
    return answer;
}