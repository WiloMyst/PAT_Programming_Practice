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
        book[temp]++;//λ��ǰ�ĸ�λ����hash��1 
        temp = temp * 2 + c;//������λ�ӷ� 
        c = 0;
        if(temp >= 10) {
            temp = temp - 10;
            c = 1;
        }
        num[i] = (temp + '0');
        book[temp]--;//λ�Ӻ�ĸ�λ����hash��1 
    }
    int flag = 0;
    for(int i = 0; i < 10; i++) {
        if(book[i] != 0)
            flag = 1;
    }
    printf("%s", (c == 1 || flag == 1) ? "No\n" : "Yes\n");//ע��������λ�н�λ��һ��No 
    if(c == 1) printf("1");
    printf("%s", num);
    return 0;
}

//property �Ʋ������� 
//permutation ���� 
