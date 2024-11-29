#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
using namespace std;
long long convert(string n, long long radix) {//radix进制数转成十进制数 
    long long sum = 0;
    int index = 0, temp = 0;
    for (auto it = n.rbegin(); it != n.rend(); it++) {
        temp = isdigit(*it) ? *it - '0' : *it - 'a' + 10;
        sum += temp * pow(radix, index++);
    }
    return sum;
}
long long find_radix(string n, long long num) {//若不用二分查找，会有一个样例超时 
    char it = *max_element(n.begin(), n.end());//注意数字中的最大表示字符可以确定基数的下界，但并不能确定基数的上界
    long long low = (isdigit(it) ? it - '0': it - 'a' + 10) + 1;
    long long high = max(num, low);//取max保证了检测尽可能多的基数值。这里基数最大值为N1+1。为什么是N1+1呢？当N2只有一位时，其大小与基数无关，例如：只要基数大于8，那么8这个数不管是在16进制下还是20进制下，都是8(10进制下），因为任何基数的0次方都是1嘛；当N2有两位或以上时，倒数第二位最小是1，那么基数为N1+1时，这个数就必然会大于等于N1+1，所以再大就没有必要比较了。
    while (low <= high) {          //为什么不能是N1？举个例子N1=10，N2=a时，start=a+1=11，end=10，所以输出Impossible，但显然在11进制下10=a 
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

//max_element函数和min_element函数定义在头文件 < algorithm >中，可用于返回一个数组或字符串中的最大值/最小值指针或迭代器 
