#include <cstdio>
#include <string.h>
using namespace std;
int book[10];
int main() {
    char num[22];
    scanf("%s", num);
    int c = 0, len = strlen(num);
    for(int i = len - 1; i >= 0; i--) {
        int temp = num[i] - '0';
        book[temp]++;//位加前的该位数字hash加1 
        temp = temp * 2 + c;//数串逐位加法 
        c = 0;
        if(temp >= 10) {
            temp = temp - 10;
            c = 1;
        }
        num[i] = (temp + '0');
        book[temp]--;//位加后的该位数字hash减1 
    }
    int flag = 0;
    for(int i = 0; i < 10; i++) {
        if(book[i] != 0)
            flag = 1;
    }
    printf("%s", (c == 1 || flag == 1) ? "No\n" : "Yes\n");//注意如果最高位有进位则一定No 
    if(c == 1) printf("1");
    printf("%s", num);
    return 0;
}

//property 财产；性质 
//permutation 排列 
