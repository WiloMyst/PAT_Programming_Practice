#include <iostream>//int范围内，连续因子最多不会超过12个 
#include <cmath>
using namespace std;
long int num, temp;
int main(){
    cin >> num;
    int first = 0, len = 0, maxn = sqrt(num) + 1;//在有两个及以上的数连乘中，因数的最大上限为sqrt(N) + 1
    for (int i = 2; i <= maxn; i++) {
        int j; 
        temp = 1;
        for (j = i; j <= maxn; j++) {
            temp *= j;
            if (num % temp != 0) break;//注意不要只取余j 
        }
        if (j - i > len) {
            len = j - i;
            first = i;
        }
    }
    if (first == 0) {//1或质数情况 
        cout << 1 << endl << num;
    } else {
        cout << len << endl;
        for (int i = 0; i < len; i++) {
            cout << first + i;
            if (i != len - 1) cout << '*';
        }
    }
    return 0;
}
