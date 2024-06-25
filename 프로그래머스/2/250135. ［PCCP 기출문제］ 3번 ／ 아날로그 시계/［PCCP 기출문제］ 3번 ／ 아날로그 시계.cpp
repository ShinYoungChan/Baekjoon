#include <string>
#include <vector>

using namespace std;

int getCount(int h,int m, int s){
     int total = h*3600+m*60+s;

     int m_alram = total*59/3600;

     int h_alram = total * 719/43200;

     int answer = m_alram+h_alram;

     if(h>=12){
         answer--;
     }
    return answer;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    
    if(h1*3600+m1*60+s1==0 ||h1*3600+m1*60+s1==43200){
        answer=1;
    }
    return getCount(h2,m2,s2)-getCount(h1,m1,s1)+answer;
}