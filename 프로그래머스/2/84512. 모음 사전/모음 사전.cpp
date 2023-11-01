#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> str;

void repeatPermutation(string vec, vector<char> perm, int depth)
{
    if (depth == perm.size()){
        string s="";
        for(int i = 0; i < perm.size(); i++)
            s+=perm[i];
        str.push_back(s);
        return;
    }
    
    for(int i = 0; i < vec.size(); i++)
    {
        perm[depth] = vec[i];
        repeatPermutation(vec, perm, depth + 1);
    }
}

int solution(string word) {
    string ch = "AEIOU";
    
    for(int i=1;i<=5;i++){
        vector<char> v(i);
        repeatPermutation(ch,v,0);
    }
    
    sort(str.begin(),str.end());
    
    return find(str.begin(),str.end(),word)-str.begin()+1;
}