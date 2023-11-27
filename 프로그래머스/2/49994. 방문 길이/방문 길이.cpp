#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int solution(string dirs) {
    int answer = 0;
    vector<tuple<int,int,int,int>> v;
    int x = 0, y = 0;
    for(int i=0;i<dirs.length();i++){
        char command = dirs[i];
        int dx,dy;
        
        if(command=='U'){
            dx = -1;
            dy = 0;
        }
        if(command=='D'){
            dx = 1;
            dy = 0;
        }
        if(command=='R'){
            dx = 0;
            dy = 1;
        }
        if(command=='L'){
            dx = 0;
            dy = -1;
        }
        if(x+dx<-5||x+dx>5||y+dy<-5||y+dy>5) continue;
        x += dx;
        y += dy;
        tuple<int,int,int,int> t = make_tuple(x,y,x-dx,y-dy);
        tuple<int,int,int,int> t1 = make_tuple(x-dx,y-dy,x,y);
        auto it = find(v.begin(),v.end(),t);
        auto it1 = find(v.begin(),v.end(),t1);
        if(it==v.end()&&it1==v.end()){
            v.push_back(t);
            v.push_back(t1);
            answer++;
        }
    }
    return answer;
}