#include <string>
#include <vector>

using namespace std;

int answer;

void dfs(int num, int count, vector<int>numbers, int target){
    if(count == numbers.size()-1){
        if(num == target)
            answer++;
        return;
    }
    count++;
    dfs(num+numbers[count], count, numbers,target);
    dfs(num-numbers[count], count, numbers,target);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers[0],0,numbers,target);
    dfs(-numbers[0],0,numbers,target);
    return answer;
}