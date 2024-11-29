#include <cstdio>
using namespace std;
int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int arr[40], index = 0;
    while(a != 0) {
        arr[index++] = a % b;
        a = a / b;
    }
    int flag = 0;
    for(int i = 0; i < index / 2; i++) {
        if(arr[i] != arr[index-i-1]) {
            printf("No\n");
            flag = 1;
            break;
        }
    }
    if(!flag) printf("Yes\n");
    for(int i = index - 1; i >= 0; i--) {
        printf("%d", arr[i]);
        if(i != 0) printf(" ");
    }
    if(index == 0)
        printf("0");
    return 0;
}

//Palindromic Number 回文数
//standard notation 标准计数法
//if and only if 当且仅当 
