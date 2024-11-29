#include <iostream>
#include <string>
using namespace std;
string a[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string b[13] = {"####", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
string s;	//[0,169)内为13进制的两位数，高位不为tret 
int len;
void func1(int t) {
    if (t / 13) cout << b[t / 13];
    if ((t / 13) && (t % 13)) cout << " ";
    if (t % 13 || t == 0) cout << a[t % 13];//高位非0，低位为0时低位不输出tret 
}
void func2() {
    int t1 = 0, t2 = 0;
    string s1 = s.substr(0, 3), s2;
    if (len > 4) s2 = s.substr(4, 3);
    for (int j = 1; j <= 12; j++) {
        if (s1 == a[j] || s2 == a[j]) t2 = j;
        if (s1 == b[j]) t1 = j;
    }
    cout << t1 * 13 + t2;
}
int main() {
    int n;
    cin >> n;	//cin>>会自动跳过读入不可见字符(空格tab回车)，不会吸收它们，因此两个cin>>之间不需要作吸收处理 
    getchar();	//但getline会吸收它们，所以这里要作吸收处理 
    for (int i = 0; i < n; i++) {
        getline(cin, s);	//getline()可以接收空格和回车，用于string类型；cin.getline(arr, 10)可以接收空格，但不能接收回车，用于字符数组 
        len = s.length();
        if (s[0] >= '0' && s[0] <= '9')
            func1(stoi(s));
        else
            func2();
        cout << endl;
    }
    return 0;
}
