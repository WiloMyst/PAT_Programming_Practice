#include <iostream>
using namespace std;
int main() {
    int n, left = 0, right = 0, a = 1, now = 1, ans = 0;
    scanf("%d", &n);
    while(n / a) {//�ۼӵ�ǰλ=1�����ָ��� 
        left = n / (a * 10), now = n / a % 10, right = n % a;
        if(now == 0) ans += left * a;//��ǰλΪ0����߿���Ϊ0~left-1���ұ߿���Ϊ0~99...9 
        else if(now == 1) ans += left * a + right + 1;//��ǰλΪ1����Ϊ0�Ļ����϶�������ұ߿���Ϊ0~right+1
        else ans += (left + 1) * a;//��ǰλ>=2����߿���Ϊ0~left���ұ߿���Ϊ0~99...9
        a = a * 10;
    }
    printf("%d", ans);
    return 0;
}

/* �磺����N=12����ͳ�Ƹ�λΪ1����������Щ��01,11��Ȼ��ͳ��ʮλΪ1�����֣�10,11,12��
   ����ÿ�ν�ͳ��1���ִ�������˳��ֵ��ظ����������ȥ�����õ�5�����֣����Ϊ5
*/
