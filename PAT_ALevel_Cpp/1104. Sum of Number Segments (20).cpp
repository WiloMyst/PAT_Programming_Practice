#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long sum = 0;
    double temp;
    for (int i = 1; i <= n; i++) { 
        cin >> temp;//对于每个值，包含它的数列的左边界有i种可能，右边界有n-i+1种可能 
        sum += (long long)(temp * 1000) * i * (n - i + 1);
    }//之所以采用long long累加而非double累加，就是要消除浮点数计算精度丢失
    printf("%.2f", sum / 1000.0);
    return 0;
}
