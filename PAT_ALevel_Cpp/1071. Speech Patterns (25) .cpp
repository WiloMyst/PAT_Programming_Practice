#include <iostream>
#include <map>
#include <cctype>
using namespace std;
int main() {
    string s, t;
    getline(cin, s);
    map<string, int> m;
    for(int i = 0; i < s.length(); i++) {
        if(isalnum(s[i])) {//��������ַ�����õ��� 
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

//synonym ͬ���
//an online avatar ����ͷ��
//carriage return �س�
//alphanumerical character ��ĸ�����ַ�  non-alphanumerical character ����ĸ�����ַ� 
//lexicographically smallest �ֵ�����С 
//the line beginning/end ����/β
//case insensitive �����ִ�Сд 