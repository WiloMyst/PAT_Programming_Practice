#include <iostream>//��¼ÿ��ϲ������ɫ��ϲ�������е�λ�ã�λ�ù����������У�book[i]=j��ʾi��ɫ��λ��Ϊj��
#include <vector>  //���������ʱ���޳�����ϲ�������е�Ԫ�أ�Ȼ���ʣ��Ԫ��ת��λ�ñ���������a�У�����λ�ð�������½������еķ�ʽ���� 
using namespace std;
int book[201], a[10001], dp[10001];//dp[]Ϊ��iλ�ý�β������½������г��� 
int main() {
    int n, m, x, l, num = 0, maxn = 0;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        scanf("%d", &x);
        book[x] = i;
    }
    scanf("%d", &l);
    for(int i = 0; i < l; i++) {
        scanf("%d", &x);
        if(book[x] >= 1)
            a[num++] = book[x];//ϲ������ɫת��λ�ô����� 
    }
    for(int i = 0; i < num; i++) {//��λ�ù��ɵ�����������½������г��� 
        dp[i] = 1;
        for(int j = 0; j < i; j++)
            if(a[i] >= a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        maxn = max(dp[i], maxn);
    }
    printf("%d", maxn);
    return 0;
}

//out of ...  ��...�� 
