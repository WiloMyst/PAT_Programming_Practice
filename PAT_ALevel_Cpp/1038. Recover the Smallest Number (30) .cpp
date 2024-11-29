#include <iostream>//贪心，局部最优到全局最优 
#include <string>
#include <algorithm>
using namespace std;
bool cmp0(string a, string b) {//妙，值得学习！(涉及按某规律排序的题想到sort及cmp) 
    return a + b < b + a;
}
string str[10010];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        cin >> str[i];
    sort(str, str + n, cmp0);
    string s;
    for(int i = 0; i < n; i++)
        s += str[i];
    while(s.length() > 1 && s[0] == '0')//前导0最多只需删到倒数第2位 
        s.erase(s.begin());//删头0 
    cout << s;
    return 0;
}

//with respect to 关于 
