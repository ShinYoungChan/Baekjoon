#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    char boardName[30][30]={'\0'};
    vector<pair<int, int>> v;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            boardName[i][j]=board[i][j];
    
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<boardName[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    while(true){
        for(int i=0;i<m-1;i++){
            for(int j=0;j<n-1;j++){
                if(boardName[i][j]==boardName[i][j+1]&&boardName[i][j]==boardName[i+1][j]&&
                   boardName[i][j]==boardName[i+1][j+1]&& boardName[i][j]!=' '){
                    v.push_back({i,j});   //i*n+j
                    v.push_back({i,j+1});
                    v.push_back({i+1,j});
                    v.push_back({i+1,j+1});
                }
            }
        }
        if(v.size()==0)
            break;
        // cout<<endl;
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        for(int i=0;i<v.size();i++){
            // boardName[v[i].first][v[i].second]=' ';
            // new,j = new-1,j(i,0 -1)
            //cout<<v[i].first<<" "<<v[i].second<<endl;
            for(int j=v[i].first;j>0;j--){
                if(boardName[j-1][v[i].second]==' ')
                    break;
                // cout<<j<<" "<<v[i].second<<endl;
                boardName[j][v[i].second]=boardName[j-1][v[i].second];
                boardName[j-1][v[i].second]=' ';
            }
            answer++;
        }
        v.clear();
    }
   
    return answer;
}