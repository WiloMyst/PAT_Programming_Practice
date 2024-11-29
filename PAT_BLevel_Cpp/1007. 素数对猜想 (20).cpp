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
        if (isprime(i-2) && isprime(i)) cnt++;//由于除了2和3之间距离为1，其它相邻素数间距离为偶数，因此不必验证i-1不是素数 
    cout << cnt;
    return 0;
}
