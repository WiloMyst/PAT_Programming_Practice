#include <iostream>		//s1有s2无的字符即一定键坏，可用散列，不能用双指针 
#include <cctype>
using namespace std;
int main() {
    string s1, s2, ans;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++)	//find()可以找字符或字符串 
        if (s2.find(s1[i]) == string::npos && ans.find(toupper(s1[i])) == string::npos)
            ans += toupper(s1[i]);	//ans里面能找到说明输出过了 
    cout << ans;
    return 0;
}
