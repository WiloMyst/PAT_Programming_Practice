#include <cstdio>
using namespace std;
int main() {
    char c[14] = {"0123456789ABC"};//打表多简单 
    printf("#");
    for(int i = 0; i < 3; i++) {
        int num;
        scanf("%d", &num);
        printf("%c%c", c[num/13], c[num%13]);
    }
    return 0;
}

//radix 基数 
