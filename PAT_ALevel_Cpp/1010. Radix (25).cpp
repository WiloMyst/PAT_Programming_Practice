#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
using namespace std;
long long convert(string n, long long radix) {//radix������ת��ʮ������ 
    long long sum = 0;
    int index = 0, temp = 0;
    for (auto it = n.rbegin(); it != n.rend(); it++) {
        temp = isdigit(*it) ? *it - '0' : *it - 'a' + 10;
        sum += temp * pow(radix, index++);
    }
    return sum;
}
long long find_radix(string n, long long num) {//�����ö��ֲ��ң�����һ��������ʱ 
    char it = *max_element(n.begin(), n.end());//ע�������е�����ʾ�ַ�����ȷ���������½磬��������ȷ���������Ͻ�
    long long low = (isdigit(it) ? it - '0': it - 'a' + 10) + 1;
    long long high = max(num, low);//ȡmax��֤�˼�⾡���ܶ�Ļ���ֵ������������ֵΪN1+1��Ϊʲô��N1+1�أ���N2ֻ��һλʱ�����С������޹أ����磺ֻҪ��������8����ô8�������������16�����»���20�����£�����8(10�����£�����Ϊ�κλ�����0�η�����1���N2����λ������ʱ�������ڶ�λ��С��1����ô����ΪN1+1ʱ��������ͱ�Ȼ����ڵ���N1+1�������ٴ��û�б�Ҫ�Ƚ��ˡ�
    while (low <= high) {          //Ϊʲô������N1���ٸ�����N1=10��N2=aʱ��start=a+1=11��end=10���������Impossible������Ȼ��11������10=a 
        long long mid = (low + high) / 2;
        long long t = convert(n, mid);
        if (t < 0 || t > num) high = mid - 1;
        else if (t == num) return mid;
        else low = mid + 1;
    }
    return -1;
}
int main() {
    string n1, n2;
    long long tag = 0, radix = 0, result_radix;
    cin >> n1 >> n2 >> tag >> radix;
    result_radix = tag == 1 ? find_radix(n2, convert(n1, radix)) : find_radix(n1, convert(n2, radix));
    if (result_radix != -1) {
        printf("%lld", result_radix);
    } else {
        printf("Impossible");
    }   
    return 0;
}

//max_element������min_element����������ͷ�ļ� < algorithm >�У������ڷ���һ��������ַ����е����ֵ/��Сֵָ�������� 
