#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

bool check(int n) {
    if(n <= 1)
        return false;
    for(int i = 2; i < n; i++)
        if(n % i == 0)
                return false;
    return true;
}

int solution(string numbers) {
    int answer = 0;
    int n = 0;
    set<int> s;
    vector<int>v;
    sort(numbers.begin(), numbers.end());
    do{
       for(int i = 1; i <= numbers.size(); i++) {
           n = stoi(numbers.substr(0, i));
           if(check(n)){
               s.insert(n);
               v.push_back(n);
           }
       }
    } while(next_permutation(numbers.begin(), numbers.end()));
    
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    answer = v.size();
    
    return answer;
}