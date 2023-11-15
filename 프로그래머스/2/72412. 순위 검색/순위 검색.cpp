#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int stringToInt(string str){
    int sum = 0;
    for(int i=0;i<str.size();i++){
        if(str[i]>='0'&&str[i]<='9'){
            sum = sum*10+(str[i]-'0');
        }
    }
    return sum;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer(query.size(),0);
    unordered_map<string,vector<int>> m;
    for(int i=0;i<info.size();i++){
        vector<vector<string>> v;
        int curr=0,pos;
        while ((pos = info[i].find(" ",curr)) != string::npos) {
            int len = pos - curr;
            vector<string> temp(2,"-");
            temp[1] = info[i].substr(curr,len);
            curr = pos+1;
            v.push_back(temp);
        }
        int num = stoi(info[i].substr(curr,info[i].size()));
        for(int i=0;i<v[0].size();i++){
            for(int j=0;j<v[1].size();j++){
                for(int k=0;k<v[2].size();k++){
                    for(int l=0;l<v[3].size();l++){
                        m[v[0][i]+v[1][j]+v[2][k]+v[3][l]].push_back(num);
                    }
                }
            }
        }
    }
    for(auto it = m.begin(); it!=m.end();it++){
        sort(it->second.begin(),it->second.end());
    }
    for(int i=0;i<query.size();i++){
        int pos;
        string str = "";
        while ((pos = query[i].find(" and ")) != string::npos) {
            str+=query[i].substr(0,pos);
            query[i] = query[i].substr(pos+5, query[i].size());
        }
        str+=query[i];
        int num = stringToInt(str);
        str = str.substr(0,str.size()-to_string(num).size());
        str.pop_back();
        answer[i]=m[str].end() - lower_bound(m[str].begin(), m[str].end(), num);
    }
    return answer;
}