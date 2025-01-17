#include <iostream>
using namespace std;
string s;
int Left, Right;
int main(){
    cin >> s;
    if (s.size() & 1) cout << "Error: " << s.size() << " digit(s)";
    else {
        for (int i = 0; i < s.size(); i++) {
            if (i < s.size() / 2) Left += s[i];
            else Right += s[i];
        }//题目告知Y的个位数<=7，因此可以利用左右串的ASCII码总和作为以下判断条件 
        if (Left + 2 == Right) cout << "Yes: " << s.substr(s.size() / 2 ) << " - " << s.substr(0, s.size() / 2) << " = 2";
        else cout << "No: " << s.substr(s.size() / 2) << " - " << s.substr(0, s.size() / 2) << " != 2";
    }
    return 0;
}
