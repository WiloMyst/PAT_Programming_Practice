#include <iostream>
#include <map>
#include <cmath>
#include <string>
using namespace std;
string s, c;
map<string,int> A = {{"ling", 0}, {"yi", 1}, {"er", 2}, {"san", 3}, {"si", 4}, {"wu", 5}, {"liu", 6}, {"qi", 7}, {"ba", 8}, {"jiu", 9}};
int main() {
    for (int I = 0; I < 11; I++) {
        cin >> s;
        if (s.size() == 1) cout << s;
        else if (s[0] == 's' && s[1] == 'q') cout << sqrt(stoi(s.substr(4)));//sqrt虽返回浮点型，但浮点型的整数输出时不带小数点及小数 
        else if (A.count(s)) cout << A[s];
        else {
            int a = 0, b = 0, i = 0;
            while(i < s.size() && isdigit(s[i])) a = a * 10 + s[i++] - '0';//一种数字串转数字的方法 
            c = s[i++];
            while(i < s.size()) b = b * 10 + s[i++] - '0';
            if (c == "+") cout << a + b;
            else if (c == "-") cout << a - b;
            else if (c == "*") cout << a * b;
            else if (c == "/") cout << a / b;
            else if (c == "%") cout << a % b;
            else cout << pow(a, b);
        }
    }
    return 0;
}
