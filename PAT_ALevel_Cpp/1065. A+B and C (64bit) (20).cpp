#include <cstdio>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        long long a, b, c;//������ǿ����䣬����������ȫ������long long�洢 
        scanf("%lld %lld %lld", &a, &b, &c);
        long long sum = a + b;
        if(a > 0 && b > 0 && sum < 0) {//�������һ������c 
            printf("Case #%d: true\n", i + 1);
        } else if(a < 0 && b < 0 && sum >= 0){//�͸����һ��С��c(ע��������Բ�ȡ�ȡ�����ȡ��-2^63����-2^63-2^63���Ϊ0) 
            printf("Case #%d: false\n", i + 1);
        } else if(sum > c) {//��������ճ��ж� 
            printf("Case #%d: true\n", i + 1);
        } else {
            printf("Case #%d: false\n", i + 1);
        }
    }
    return 0;
}
