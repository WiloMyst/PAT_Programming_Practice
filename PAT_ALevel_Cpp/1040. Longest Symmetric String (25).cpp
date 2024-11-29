#include <iostream>//动态规划(空间换时间，发掘递推方程和边界值)，O(n^3)缩为O(n^2) 
using namespace std;
int dp[1010][1010];//dp[i][j]表示s[i]到s[j]所表示的字串是否是回文字串
int main() {
    string s;
    getline(cin, s);
    int len = s.length(), ans = 1;
    for(int i = 0; i < len; i++) {//初始化长度为1和2的子串的dp[][] 
        dp[i][i] = 1;
        if(i < len - 1 && s[i] == s[i+1]) {
            dp[i][i+1] = 1;
            ans = 2;
        }
    }
    for(int L = 3; L <= len; L++) {//从长度为3开始更新dp[][] 
        for(int i = 0; i + L - 1 < len; i++) {
            int j = i + L -1;
            if(s[i] == s[j] && dp[i+1][j-1] == 1) {//首尾相等且内部回文，则更新 
                dp[i][j] = 1;
                ans = L;
            }
        }
    }
    printf("%d", ans);
    return 0;
}
