#include <iostream>
#include <map>
#include <cctype>
using namespace std;
int main() {
    string s, t;
    getline(cin, s);
    map<string, int> m;
    for(int i = 0; i < s.length(); i++) {
        if(isalnum(s[i])) {//采用逐加字符法获得单词 
            s[i] = tolower(s[i]);
            t += s[i];
        }
        if(!isalnum(s[i]) || i == s.length() - 1){
            if(t.length() != 0) m[t]++;
            t = "";
        }
    }
    int maxn = 0;
    for(auto it = m.begin(); it != m.end(); it++) {
        if(it->second > maxn) {
            t = it->first;
            maxn = it->second;
        }
    }
    cout << t << " " << maxn;
    return 0;
}

//synonym 同义词
//an online avatar 在线头像
//carriage return 回车
//alphanumerical character 字母数字字符  non-alphanumerical character 非字母数字字符 
//lexicographically smallest 字典序最小 
//the line beginning/end 行首/尾
//case insensitive 不区分大小写 
