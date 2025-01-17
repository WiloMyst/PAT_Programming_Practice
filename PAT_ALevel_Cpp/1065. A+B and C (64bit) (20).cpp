#include <cstdio>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        long long a, b, c;//看清楚是开区间，输入数据完全可以用long long存储 
        scanf("%lld %lld %lld", &a, &b, &c);
        long long sum = a + b;
        if(a > 0 && b > 0 && sum < 0) {//和正溢出一定大于c 
            printf("Case #%d: true\n", i + 1);
        } else if(a < 0 && b < 0 && sum >= 0){//和负溢出一定小于c(注意这里可以不取等。若能取到-2^63，则-2^63-2^63结果为0) 
            printf("Case #%d: false\n", i + 1);
        } else if(sum > c) {//不溢出就照常判断 
            printf("Case #%d: true\n", i + 1);
        } else {
            printf("Case #%d: false\n", i + 1);
        }
    }
    return 0;
}
