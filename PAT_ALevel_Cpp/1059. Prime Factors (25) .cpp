#include <cstdio>//int��Χ�µ�����������������Ӹ������Ϊ10��������������Ǽ�����˵ 
#include <vector>
using namespace std;
vector<int> prime(50000, 1);//���⿪n+1�����ڴ泬�ޡ�Ҳ���Կ�����n+1����Ȼ�󵥶�������ڸ���n���Ǹ������� 
int main() {
    for(int i = 2; i < 50000; i++)//ɸ���������� 
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
