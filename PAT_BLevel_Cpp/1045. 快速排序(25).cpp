#include <iostream>
#include <algorithm>
#include <vector>
int v[100000];
using namespace std;
int main() {
    int n, max = 0, cnt = 0;
    scanf("%d", &n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if(a[i] == b[i] && b[i] > max)	//���ڸ�������ͬ������Ԫ����������λ����ʱ���ſ�������Ԫ 
            v[cnt++] = b[i];
        if (b[i] > max)	//�����Ҫ����ǰ��Ԫ�ض�С���� 
            max = b[i];
    }
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++) {
        if (i != 0) printf(" ");
        printf("%d", v[i]);
    }
    printf("\n");
    return 0;
}
