#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long sum = 0;
    double temp;
    for (int i = 1; i <= n; i++) { 
        cin >> temp;//����ÿ��ֵ�������������е���߽���i�ֿ��ܣ��ұ߽���n-i+1�ֿ��� 
        sum += (long long)(temp * 1000) * i * (n - i + 1);
    }//֮���Բ���long long�ۼӶ���double�ۼӣ�����Ҫ�������������㾫�ȶ�ʧ
    printf("%.2f", sum / 1000.0);
    return 0;
}
