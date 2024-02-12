#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string,int> um;
    for(auto c:clothes){
        um[c[1]] += 1;
    }
    for(auto m:um){
        answer *= (m.second + 1);
    }
    return answer - 1;
}