#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double r1, p1, r2, p2, A, B;
    cin >> r1 >> p1 >> r2 >> p2;
    A = r1 * r2 * cos(p1) * cos(p2) - r1 * r2 * sin(p1) * sin(p2);
    B = r1 * r2 * cos(p1) * sin(p2) + r1 * r2 * sin(p1) * cos(p2);
    if (A + 0.005 >= 0 && A < 0)	//C++�ĸ���������-0�ģ����Ը�������������0ʱ�����뽫-0�ֶ�����0��c++��round����Ҳ���ܴ���-0���� 
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
}	//1.С�����ֵ�����������������á�%.nf+���㴦����ʵ�֡����������ǶԾ���ֵ���еģ������������������뷽���෴��
	//2.��������������ԼӰ�ģ�ٳ�����������������Լ���ģ�ٳ���Ӹ��㴦�� 
