#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int maxhealth = health, time = 0;
    for(int i=0;i<attacks.size();i++){
        int dTime = attacks[i][0];
        int damage=attacks[i][1];
        int diff = dTime - time-1;
        health += diff*bandage[1] +diff/bandage[0] * bandage[2];
        if(health > maxhealth) health = maxhealth;
        health-=damage;
        time = dTime;
        if(health<=0) break;
    }
    return health<=0 ? -1:health;
}