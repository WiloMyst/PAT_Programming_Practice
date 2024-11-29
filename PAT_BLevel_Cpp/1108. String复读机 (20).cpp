#include <iostream>
using namespace std;
string s = "String", in;
int a[200], flag = 1;//字符哈希可以用int a[200] 
int main() {
    cin >> in;
    for (auto it : in) a[it]++;
    while (flag) {//未输出过东西就停止循环 
        flag = 0;
        for (int i = 0; i < 6; i++) {
            if (a[s[i]]) {
                cout << s[i];
                a[s[i]]--;
                flag = 1;
            }
        }
    }
    return 0;
}
