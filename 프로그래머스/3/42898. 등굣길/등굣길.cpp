#include <string>
#include <vector>

using namespace std;

int map[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    for(auto p:puddles){
        map[p[1]][p[0]] = -1;
    }
    map[1][1] = 1;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(map[i][j]==-1)continue;
            if(map[i][j-1]!=-1)
                map[i][j] += map[i][j-1];
            if(map[i-1][j]!=-1)
                map[i][j] += map[i-1][j];
            map[i][j] %= 1000000007;
        }
    }
    return map[n][m];
}