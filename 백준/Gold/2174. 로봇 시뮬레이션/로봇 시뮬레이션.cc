#include <iostream>
using namespace std;
 
int di[] = { -1,0,1,0 };
int dj[] = { 0,1,0,-1 };
 
//가로,세로,로봇 개수,명령 개수
int A, B, N, M;
 
//로봇이 움직이는 맵
int map[102][102];
//로봇마다 정보(행,열,방향)
int robotInfo[101][3];
 
bool crash = false;
 
bool simulation(int id, char cmd, int cmdCnt) {
 
    //명령내릴 로봇 위치,방향 저장
    int tmpi = robotInfo[id][0];
    int tmpj = robotInfo[id][1];
    int tmpDir = robotInfo[id][2];
 
    map[tmpi][tmpj] = 0;
 
    //명령 반복 횟수만큼 반복
    while (cmdCnt--) {
        if (cmd == 'L') {
            if (tmpDir == 0) {
                tmpDir = 3;
            }
            else {
                tmpDir--;
            }
        }
        else if (cmd == 'R') {
            if (tmpDir == 3) {
                tmpDir = 0;
            }
            else {
                tmpDir++;
            }
        }
        else {
            tmpi += di[tmpDir];
            tmpj += dj[tmpDir];
 
            //벽에 충돌한 경우
            if (tmpi <= 0 || tmpj <= 0 || tmpi > A || tmpj > B) {
                cout << "Robot " << id << " crashes into the wall" << "\n";
                return true;
            }
 
            //다른 로봇에 충돌한 경우
            if (map[tmpi][tmpj] != 0) {
                cout << "Robot " << id << " crashes into robot " << map[tmpi][tmpj] << "\n";
                return true;
            }
        }
    }
 
    //충돌이 발생하지 않았을 경우, 로봇위치 변경
    map[tmpi][tmpj] = id;
 
    robotInfo[id][0] = tmpi;
    robotInfo[id][1] = tmpj;
    robotInfo[id][2] = tmpDir;
 
    return false;
}
 
int main() {
 
    //1.입력
    cin >> B >> A >> N >> M;
    for (int i = 1; i <= N; i++) {
        int tmpi, tmpj, tmpDir;
        char tmp;
 
        cin >> tmpj >> tmpi >> tmp;
 
        if (tmp == 'N') {
            tmpDir = 0;
        }
        else if (tmp == 'E') {
            tmpDir = 1;
        }
        else if (tmp == 'S') {
            tmpDir = 2;
        }
        else {
            tmpDir = 3;
        }
 
        //배열index 조정
        robotInfo[i][0] = (A + 1) - tmpi;
        robotInfo[i][1] = tmpj;
        robotInfo[i][2] = tmpDir;
 
        map[robotInfo[i][0]][robotInfo[i][1]] = i;
    }
    
    //2.명령 수행
    for (int i = 1; i <= M; i++) {
        int id, cmdCnt;
        char cmd;
        cin >> id >> cmd >> cmdCnt;
 
        if (!crash) {
            crash = simulation(id, cmd, cmdCnt);
        }
    }
 
    if (!crash) {
        cout << "OK" << "\n";
    }
 
    return 0;
}