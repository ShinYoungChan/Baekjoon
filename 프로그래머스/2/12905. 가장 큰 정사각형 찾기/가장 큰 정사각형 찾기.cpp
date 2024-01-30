#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<vector<int>> board)
{
    int ans = board[0][0];
    for(int i=1;i<board.size();i++){
        for(int j=1;j<board[0].size();j++){
            if(board[i][j]){
                board[i][j] = min(min(board[i][j-1],board[i-1][j]),board[i-1][j-1])+1;
                if(ans<board[i][j]) ans = board[i][j];
            }
        }
    }
    return ans*ans;
}