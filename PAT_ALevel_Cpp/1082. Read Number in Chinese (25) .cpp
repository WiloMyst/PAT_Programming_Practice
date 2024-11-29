#include <iostream>
#include <string>
#include <vector>
using namespace std;
string num[10] = { "ling","yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
string c[6] = { "Ge","Shi", "Bai", "Qian", "Yi", "Wan" };
int J[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};//每位对应的mod 
vector<string> res;
int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << "ling";
        return 0;
    }
    if (n < 0) {
        cout << "Fu ";
        n = -n;
    }
    int part[3];//每4位分一段 
    part[0]= n / 100000000; 
    part[1]= (n % 100000000) / 10000;
    part[2] = n % 10000;
    bool zero = false;
    int printCnt = 0;
    for (int i = 0; i < 3; i++) {
        int temp = part[i];
        for (int j = 3; j >= 0; j--) {
            int curPos = 8 - i * 4 + j;//数字第几位 - 1(下标) 
            if (curPos >= 9) continue;//忽略高于9位部分 
            int cur = (temp / J[j]) % 10;
            if (cur != 0) {
                if (zero) {//必须先碰到一个非0数才可能在它前面输出ling 
                    printCnt++ == 0 ? cout<<"ling" : cout<<" ling";
                    zero = false;
                }
                if (j == 0)
                    printCnt++ == 0 ? cout << num[cur] : cout << ' ' << num[cur];
                else                             
                    printCnt++ == 0 ? cout << num[cur] << ' ' << c[j] : cout << ' ' << num[cur] << ' ' << c[j];
            } else {//若当前数字为0，则可能将要输出ling，置标记为true 
                if (!zero && j != 0 && n / J[curPos] >= 10) zero = true;//当前位为0，且不是该段个位，且不是无效的前缀0 
            }
        }
        if (i != 2 && part[i] > 0) cout << ' ' << c[i + 4];
    }
    return 0;
}
