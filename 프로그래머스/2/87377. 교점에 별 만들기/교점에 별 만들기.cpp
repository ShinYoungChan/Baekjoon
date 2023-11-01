#include <string>
#include <vector>
#include <set>

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    set<pair<int,int>> s;
    int minX = 0, maxX = 0, minY = 0, maxY = 0;
    bool flag = false;
    for(int i=0;i<line.size()-1;i++){   
        for(int j=i+1;j<line.size();j++){
            long div = ((long)line[i][0]*line[j][1] - (long)line[i][1]*line[j][0]);
            long x = ((long)line[i][1]*line[j][2] - (long)line[i][2]*line[j][1]);
            long y = ((long)line[i][2]*line[j][0] - (long)line[i][0]*line[j][2]);
            if(div==0||x%div!=0||y%div!=0)
                continue;
            int mx = x/div;
            int my = y/div;
            s.insert({mx,my});
            if(!flag){
                minX=mx;maxX=mx;minY=my;maxY=my;
                flag=true;
            }
            else{
                if(minX>mx)minX = mx;
                else if(maxX<mx)maxX = mx;
                if(minY>my)minY = my;
                else if(maxY<my)maxY = my;
            }
        }
    }
    int x = maxX - minX + 1;
    int y = maxY - minY + 1;
    vector<string> answer(y);
    for(int i=0;i<y;i++)
        answer[i] = string(x, '.');
    for(auto a:s){
        answer[maxY-a.second][a.first-minX]='*';
    }
    return answer;
}