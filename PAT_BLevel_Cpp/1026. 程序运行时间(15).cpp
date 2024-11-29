#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    int n = ((b - a) + 50) / 100;	//正数四舍五入可以加半模再除。负数四舍五入可以减半模再除外加负零处理 
    int hour = n / 3600;
    n = n % 3600;
    int minute = n / 60, second = n % 60;
    printf("%02d:%02d:%02d", hour, minute, second);
    return 0;
}
