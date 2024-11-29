#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(char a, char b) {return a > b;}	//排序时非递增/非递减也用>和< 
int main() {
    string s;
    cin >> s;
    s.insert(0, 4 - s.length(), '0');	//开头添加适量的0保证四位，中间是个数 
    do {
        string a = s, b = s;
        sort(a.begin(), a.end(), cmp);
        sort(b.begin(), b.end());
        int result = stoi(a) - stoi(b);		//string转int 
        s = to_string(result);
        s.insert(0, 4 - s.length(), '0');	//开头添加适量的0保证四位，中间是个数 
        cout << a << " - " << b << " = " << s << endl;
    } while (s != "6174" && s != "0000");
    return 0;
}
