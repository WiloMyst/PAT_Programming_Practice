#include <iostream>
using namespace std;
int main() {
    int n, left = 0, right = 0, a = 1, now = 1, ans = 0;
    scanf("%d", &n);
    while(n / a) {//累加当前位=1的数字个数 
        left = n / (a * 10), now = n / a % 10, right = n % a;
        if(now == 0) ans += left * a;//当前位为0，左边可能为0~left-1，右边可能为0~99...9 
        else if(now == 1) ans += left * a + right + 1;//当前位为1，在为0的基础上额外加上右边可能为0~right+1
        else ans += (left + 1) * a;//当前位>=2，左边可能为0~left，右边可能为0~99...9
        a = a * 10;
    }
    printf("%d", ans);
    return 0;
}

/* 如：对于N=12，先统计个位为1的数字有哪些：01,11，然后统计十位为1的数字：10,11,12，
   由于每次仅统计1出现次数，因此出现的重复数字无需减去，共得到5个数字，结果为5
*/
