#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = -1;
    vector<string>s;
    for (int i = 0; i < skill_trees.size(); i++) {
        s.push_back(skill_trees[i]);
        for (int j = 0; j < skill.length(); j++) {
            skill_trees[i].erase(remove(skill_trees[i].begin(), skill_trees[i].end(), skill[j]), skill_trees[i].end());
        }
    }
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < skill_trees[i].length(); j++) {
            s[i].erase(remove(s[i].begin(), s[i].end(), skill_trees[i][j]), s[i].end());
        }
        if (skill.find(s[i]) != string::npos && skill[0] == s[i][0]||s[i].empty()) {
            answer++;
        }
    }

    return answer + 1;
}