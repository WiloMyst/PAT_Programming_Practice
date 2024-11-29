#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int main() {
    int n, cnt = 0;
    char a[50], b[50];
    double temp = 0.0, sum = 0.0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        scanf("%s", a);
        sscanf(a, "%lf", &temp);
        sprintf(b, "%.2f",temp);//这样就可以通过比较字符串是否一致来得出合不合法，其中aaa存为0.000，2.3.4存为2.300 
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
        printf("The average of 1 number is %.2f", sum);//单数number不加s 
    else if(cnt > 1)
        printf("The average of %d numbers is %.2f", cnt, sum / cnt);
    else
        printf("The average of 0 numbers is Undefined");
    return 0;
}

/*  sscanf和sprintf可实现字符串-数字转换，stod和to_string也可以
    但后者对奇怪的输入会报错或不执行，前者总会正常执行取前缀合法部分作为输入，不合法输入作0处理，例如：
    aaa -> 0.000000 -> 0.00           2.3.4 -> 2.300000 -> 2.30
    2b4.5 -> 2.000000 -> 2.00
*/ 
