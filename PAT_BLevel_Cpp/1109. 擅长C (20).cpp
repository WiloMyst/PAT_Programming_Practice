#include <iostream>
using namespace std;
char a[26][7][5], out[7][100];//a为哈希大字母表，out为单词输出点阵 
string s;
int main() {
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 100; j++)
            out[i][j] = ' ';//把点阵所有字符设为空格 
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 7; j++)
            for (int k = 0; k < 5; k++)
                cin >> a[i][j][k];//cin>>即使是读取字符，也会忽略空格Tab回车 
    getchar();
    getline(cin, s);
    for (int i = 0, j, flag = 0; i < s.size(); i++) {
        j = i;	//双指针指向每个单词首元素和尾元素下一个元素 
        while (j < s.size() && s[j] >= 'A' && s[j] <= 'Z') j++;
        if (i == j) continue;
        for (int k = i; k < j; k++)
            for (int l = 0; l < 7; l++)
                for (int m = 0; m < 5; m++)
                    out[l][m + (k - i) * 6] = a[s[k] - 'A'][l][m];//把单词中各字符的大字覆盖入点阵中 
        if (flag) cout << '\n';//大单词之间的空行 
        for (int k = 0; k < 7; k++) {
            for (int l = 0; l < 6 * (j - i) - 1; l++) cout << out[k][l];
            cout << '\n';
            flag = 1;
        }
        i = j;
    }
    return 0;
}
