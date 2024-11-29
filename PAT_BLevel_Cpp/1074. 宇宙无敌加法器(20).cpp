#include <iostream>
using namespace std;
int main() {
    string s, s1, s2, ans;
    int carry = 0, flag = 0;
    cin >> s >> s1 >> s2;
    ans = s;
    string ss1(s.length() - s1.length(), '0');//定义一个字符串，(长度，各个字符初值为'0') 
    s1 = ss1 + s1;//令2个加数长度大于等于进制表
    string ss2(s.length() - s2.length(), '0');
    s2 = ss2 + s2;
    for(int i = s.length() - 1; i >= 0; i--) {
        int mod = s[i] == '0' ? 10 : (s[i] - '0');
        ans[i] = (s1[i] - '0' + s2[i] - '0' + carry) % mod + '0';
        carry = (s1[i] - '0' + s2[i] - '0' + carry) / mod;
    }
    if (carry != 0) ans = '1' + ans;//注意输入数据每一位是不同进制的，每位数符不可能超过数符表示范围，这样每位的进位最多为1 
    for(int i = 0; i < ans.length(); i++) {//注意本题结果可能是超过9*10^18(19位的十进制)，longlong也无法表示，只能字符串输出 
        if (ans[i] != '0' || flag == 1) {//遇到第一个非0数字，置flag为1，后面位无条件输出 
            flag = 1;
            cout << ans[i];
        }
    }
    if (flag == 0) cout << 0;
    return 0;
}
