#include <iostream>
#include <cstdlib>
using namespace std;
long long gcd(long long a, long long b) {return b == 0 ? abs(a) : gcd(b, a % b);}
int main() {
    long long n, a, b, suma = 0, sumb = 1, gcdvalue;//注意分数应当初始化为"0/1" 
    scanf("%lld", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld/%lld", &a, &b);
        gcdvalue = gcd(a, b);
        a = a / gcdvalue;
        b = b / gcdvalue;
        suma = a * sumb + suma * b;
        sumb = b * sumb;
        gcdvalue = gcd(suma, sumb);
        sumb = sumb / gcdvalue;
        suma = suma / gcdvalue;
    }
    long long integer = suma / sumb;
    suma = suma - (sumb * integer);
    if(integer != 0) {
        printf("%lld", integer);
        if(suma != 0) printf(" ");
    }
    if(suma != 0)//suma==0则只有整数部分 
        printf("%lld/%lld", suma, sumb);
    if(integer == 0 && suma == 0)
        printf("0");
    return 0;
}

//rational number 有理数
//numerator/denominator 分子/分母 
