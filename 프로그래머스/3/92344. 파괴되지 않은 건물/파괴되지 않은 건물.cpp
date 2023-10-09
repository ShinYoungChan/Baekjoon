#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int sum[1002][1002];
    int row = board.size();
    int col = board[0].size();
    for(int i=0;i<skill.size();i++){
        int r1 = skill[i][1];
        int c1 = skill[i][2];
        int r2 = skill[i][3];
        int c2 = skill[i][4];
        if(skill[i][0]==1){
            // (x1, y1) = n, (x2+1, y1) = -n, (x1, y2+1) = -n, (x2+1, y2+1) = n
            sum[r1][c1] += -skill[i][5];
            sum[r1][c2+1] += skill[i][5];
            sum[r2+1][c1] += skill[i][5];
            sum[r2+1][c2+1] += -skill[i][5];
        }
        else{
            sum[r1][c1] += skill[i][5];
            sum[r1][c2+1] += -skill[i][5];
            sum[r2+1][c1] += -skill[i][5];
            sum[r2+1][c2+1] += skill[i][5];
        }
    }
    for(int i=0;i<row+1;i++){
        for(int j=0;j<col+1;j++){
            sum[i][j+1] += sum[i][j];
        }
    }
    for(int i=0;i<row+1;i++){
        for(int j=0;j<col+1;j++){
            sum[j+1][i] += sum[j][i];
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            board[i][j]+=sum[i][j];
            if(board[i][j]>0)
                answer++;
        }
    }
    return answer;
}