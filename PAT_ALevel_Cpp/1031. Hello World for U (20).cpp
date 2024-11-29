#include <iostream>
#include <string.h>
using namespace std;
int main() {//可以先在点阵中填写，然后再输出点阵 
    char c[81], u[30][30];
    memset(u, ' ', sizeof(u));
    scanf("%s", c);
    int n = strlen(c) + 2;//注意看清楚题中n1,n2,n3的含义 
    int n1 = n / 3, n2 = n / 3 + n % 3, index = 0;//先平分长度，剩余给n2 
    for(int i = 0; i < n1; i++) u[i][0] = c[index++];
    for(int i = 1; i <= n2 - 2; i++) u[n1-1][i] = c[index++];
    for(int i = n1 - 1; i >= 0; i--) u[i][n2-1] = c[index++];
    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n2; j++) 
            printf("%c", u[i][j]);
        printf("\n");
    }
    return 0;
}

//as squared as possible 尽可能的平方 
