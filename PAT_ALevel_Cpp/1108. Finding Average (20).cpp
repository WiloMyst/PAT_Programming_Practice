#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
    int n, cnt = 0;
    char a[50], b[50];
    double temp = 0.0, sum = 0.0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        scanf("%s", a);
        sscanf(a, "%lf", &temp);
        sprintf(b, "%.2f",temp);//�����Ϳ���ͨ���Ƚ��ַ����Ƿ�һ�����ó��ϲ��Ϸ�������aaa��Ϊ0.000��2.3.4��Ϊ2.300 
        int flag = 0;
        for(int j = 0; j < strlen(a); j++)
            if(a[j] != b[j]) flag = 1;
        if(flag || temp < -1000 || temp > 1000) {
            printf("ERROR: %s is not a legal number\n", a);
            continue;
        } else {
            sum += temp;
            cnt++;
        }
    }
    if(cnt == 1)
        printf("The average of 1 number is %.2f", sum);//����number����s 
    else if(cnt > 1)
        printf("The average of %d numbers is %.2f", cnt, sum / cnt);
    else
        printf("The average of 0 numbers is Undefined");
    return 0;
}

/*  sscanf��sprintf��ʵ���ַ���-����ת����stod��to_stringҲ����
    �����߶���ֵ�����ᱨ����ִ�У�ǰ���ܻ�����ִ��ȡǰ׺�Ϸ�������Ϊ���룬���Ϸ�������0���������磺
    aaa -> 0.000000 -> 0.00           2.3.4 -> 2.300000 -> 2.30
    2b4.5 -> 2.000000 -> 2.00
*/ 

//decimal places С����λ 
//accurate up to ��ȷ�� 