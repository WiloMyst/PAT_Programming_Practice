#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double r1, p1, r2, p2, A, B;
    cin >> r1 >> p1 >> r2 >> p2;
    A = r1 * r2 * cos(p1) * cos(p2) - r1 * r2 * sin(p1) * sin(p2);
    B = r1 * r2 * cos(p1) * sin(p2) + r1 * r2 * sin(p1) * cos(p2);
    if (A + 0.005 >= 0 && A < 0)	//C++的浮点数是有-0的，所以负数四舍五入变成0时，必须将-0手动调成0。c++的round函数也不能处理-0问题 
        printf("0.00");
    else
        printf("%.2f", A);
    if(B >= 0)
        printf("+%.2fi", B);
    else if (B + 0.005 >= 0 && B < 0)
        printf("+0.00i");
    else
        printf("%.2fi", B);
    return 0;
}	//1.小数部分的四舍五入输出可以用“%.nf+负零处理”来实现。四舍五入是对绝对值进行的，所以正数负数的舍入方向相反。
	//2.正数四舍五入可以加半模再除。负数四舍五入可以减半模再除外加负零处理 
