#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long sum = 0;
    double temp;
    for (int i = 1; i <= n; i++) { 
        cin >> temp;
        sum += (long long)(temp * 1000) * i * (n - i + 1);
    }	//之所以采用long long累加而非double累加，就是要消除精度丢失 
    printf("%.2f", sum / 1000.0);
    return 0;
}

//有的十进制浮点数使用二进制无法精确表示只能无限接近，在字长的限制下不可避免会产生舍入误差，这些细微的误差在N较大时多次累加会产生较大误差，所以建议不要使用double类型进行多次累加的精确计算
