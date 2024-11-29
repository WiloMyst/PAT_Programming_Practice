#include <cstdio>
#include <cmath>
using namespace std;
bool isprime(int n) {//注意，某个数是不是素数与进制系统无关 
    if(n <= 1) return false;
    int sqr = int(sqrt(n * 1.0));
    for(int i = 2; i <= sqr; i++)
        if(n % i == 0)
            return false;
    return true;
}
int main() {
    int n, d;
    while(scanf("%d", &n) != EOF) {
        if(n < 0) break;
        scanf("%d", &d);
        if(!isprime(n)) {
            printf("No\n");
            continue;
        }
        int len = 0, arr[100];
        while(n != 0){//转为反转后的d进制 
            arr[len++] = n % d;
            n = n / d;
        }
        for(int i = 0; i < len; i++)//转为十进制 
            n = n * d + arr[i];
        printf("%s", isprime(n) ? "Yes\n" : "No\n");//应在十进制下判断是不是素数 
    }
    return 0;
}

//radix 基数，进制 
