#include <iostream>
using namespace std;
bool isprime(int a) {
    for (int i = 2; i * i <= a; i++)
        if (a % i == 0) return false;
    return true;
}
int main() {
    int N, cnt = 0;
    cin >> N;
    for (int i = 5; i <= N; i++)
        if (isprime(i-2) && isprime(i)) cnt++;//���ڳ���2��3֮�����Ϊ1�������������������Ϊż������˲�����֤i-1�������� 
    cout << cnt;
    return 0;
}
