#include <iostream>
using namespace std;
int main() {
    string s;
    cin >> s;
    int i = 0;              //科学计数法转普通计数法步骤：
    while (s[i] != 'E') i++;//一分底数和指数
    string t = s.substr(1, i-1);
    int n = stoi(s.substr(i+1));		//string转int时+-号也会被转换 
    if (s[0] == '-') cout << "-";//二放负号
    if (n < 0) {//三按指数<0还是>=0分类讨论
        cout << "0.";
        for (int j = 0; j < abs(n) - 1; j++) cout << '0';
        for (int j = 0; j < t.length(); j++)
            if (t[j] != '.') cout << t[j];
    } else {
        cout << t[0];
        int cnt, j;
        for (j = 2, cnt = 0; j < t.length() && cnt < n; j++, cnt++) cout << t[j];
        if (j == t.length()) {
            for (int k = 0; k < n - cnt; k++) cout << '0';
        } else {
            cout << '.';
            for (int k = j; k < t.length(); k++) cout << t[k];
        }
    }
    return 0;
}
