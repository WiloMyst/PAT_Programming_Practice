#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long sum = 0;
    double temp;
    for (int i = 1; i <= n; i++) { 
        cin >> temp;
        sum += (long long)(temp * 1000) * i * (n - i + 1);
    }	//֮���Բ���long long�ۼӶ���double�ۼӣ�����Ҫ�������ȶ�ʧ 
    printf("%.2f", sum / 1000.0);
    return 0;
}

//�е�ʮ���Ƹ�����ʹ�ö������޷���ȷ��ʾֻ�����޽ӽ������ֳ��������²��ɱ���������������Щϸ΢�������N�ϴ�ʱ����ۼӻ�����ϴ������Խ��鲻Ҫʹ��double���ͽ��ж���ۼӵľ�ȷ����
