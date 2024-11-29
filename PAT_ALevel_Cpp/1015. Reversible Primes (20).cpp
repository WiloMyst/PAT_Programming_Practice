#include <cstdio>
#include <cmath>
using namespace std;
bool isprime(int n) {//ע�⣬ĳ�����ǲ������������ϵͳ�޹� 
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
        while(n != 0){//תΪ��ת���d���� 
            arr[len++] = n % d;
            n = n / d;
        }
        for(int i = 0; i < len; i++)//תΪʮ���� 
            n = n * d + arr[i];
        printf("%s", isprime(n) ? "Yes\n" : "No\n");//Ӧ��ʮ�������ж��ǲ������� 
    }
    return 0;
}

//radix ���������� 
