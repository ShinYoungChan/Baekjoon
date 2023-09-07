#include <string>
#include <vector>
#include <iostream>

using namespace std;

int first[8][2] = {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
int second[8][2] = {{0,2},{2,2},{2,0},{2,-2},{0,-2},{-2,-2},{-2,0},{-2,2}};

bool check(int x,int y, vector<string> board){
    for(int i=0;i<8;i++){
        int mx1 = x + first[i][0];
        int my1 = y + first[i][1];
        int mx2 = x + second[i][0];
        int my2 = y + second[i][1];
        if(mx1<0||mx1>2||my1<0||my1>2||mx2<0||mx2>2||my2<0||my2>2)continue;
        if(board[mx1][my1]==board[x][y]&&board[mx2][my2]==board[x][y])return true;
    }
    return false;
}

int solution(vector<string> board) {
    int answer = 1;
    int oCnt = 0;
    int xCnt = 0;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            if(board[i][j]=='O') oCnt++;
            else if(board[i][j]=='X') xCnt++;
        }
    }
    bool oFlag = false;
    bool xFlag = false;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            if(board[i][j]=='O'&&check(i,j,board)){
                oFlag=true;
            }
            if(board[i][j]=='X'&&check(i,j,board)){
                xFlag=true;
            }
        }
    }
    if(oCnt-xCnt>=2||xCnt>oCnt)answer = 0;
    if(oFlag&&xFlag){
        answer = 0;
    }
    if(oFlag){
        if(oCnt==xCnt)answer = 0;
    }
    if(xFlag){
        if(oCnt!=xCnt)answer = 0;
    }
    return answer;
}