#include <cstdio>//int范围下的数，其相异的质因子个数最大为10，但最大质因子是几不好说 
#include <vector>
using namespace std;
vector<int> prime(50000, 1);//本题开n+1个会内存超限。也可以开根号n+1个，然后单独处理大于根号n的那个质因子 
int main() {
    for(int i = 2; i < 50000; i++)//筛法求素数表 
        for(int j = 2; j * i < 50000; j++)
            prime[j * i] = 0;
    long int a;
    scanf("%ld", &a);
    printf("%ld=", a);
    if(a == 1) printf("1");
    bool state = false;
    for(int i = 2; i < 50000 && a >= 2; i++) {
        int cnt = 0, flag = 0;
        while(prime[i] == 1 && a % i == 0) {
            cnt++;
            a = a / i;
            flag = 1;
        }
        if(flag) {
            if(state) printf("*");
            printf("%d", i);
            state = true;
        }
        if(cnt >= 2) printf("^%d", cnt);
    }
    return 0;
}
