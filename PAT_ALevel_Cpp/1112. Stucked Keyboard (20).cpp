#include <iostream>
#include <map>
#include <cstdio>
#include <set>
using namespace std;
bool sureNoBroken[256];//哪些键没坏 
int main() {
    int k, cnt = 1;
    scanf("%d", &k);
    string s;
    cin >> s;
    map<char, bool> m;//哪些键坏了(也可以不用这个m) 
    set<char> printed;
    char pre = '#';
    s = s + '#';//尾部添加一个多余字符，用于统一最后一个字符的操作 
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == pre) {
            cnt++;
        } else {
            if(cnt % k != 0) {
                sureNoBroken[pre] = true;
            }
            cnt = 1;
        }
        if(i != s.length() - 1) m[s[i]] = (cnt % k == 0);
        pre = s[i];
    }
    for(int i = 0; i < s.length() - 1; i++) {
        if(sureNoBroken[s[i]] == true)
            m[s[i]] = false;
    }
    for(int i = 0; i < s.length() - 1; i++) {
        if(m[s[i]] && printed.find(s[i]) == printed.end()) {//保证坏键只被打印一次 
            printf("%c", s[i]);
            printed.insert(s[i]);
        }
    }
    printf("\n");
    for(int i = 0; i < s.length() - 1; i++) {
        printf("%c", s[i]);
        if(m[s[i]])
            i = i + k - 1;
    }
    return 0;
}

//stucked 卡死的 
