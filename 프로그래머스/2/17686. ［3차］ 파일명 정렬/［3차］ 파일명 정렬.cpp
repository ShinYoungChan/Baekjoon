#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct str {
    string head="";
    int num=0;
    int idx;
};

bool compare(const str& s1, const str& s2) {
    if (s1.head == s2.head) {
        if (s1.num == s2.num)
            return s1.idx < s2.idx;
        return s1.num < s2.num;
    }
    return s1.head < s2.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<str> vec;
    for (int i = 0; i < files.size(); i++) {
        str ss;
        string s = "";
        string n = "";
        for (int j = 0; j < files[i].size(); j++) {
            if (isdigit(files[i][j])&&n.size()<5) {
                if(ss.head.size()==0)
                    ss.head = s;
                n += files[i][j];
            }
            else {
                if (n.size() != 0) {
                    ss.num = stoi(n);
                    break;
                }
                if (files[i][j] >= 'a' && files[i][j] <= 'z') {
                    s += files[i][j] - 32;
                }
                else
                    s += files[i][j];
            }
        }
        if (ss.num == 0)
            ss.num = stoi(n);
        ss.idx = i;
        vec.push_back(ss);
    }
    stable_sort(vec.begin(), vec.end(), compare);
    for (auto vv : vec) {
        answer.push_back(files[vv.idx]);
    }
    return answer;
}