#include <iostream>
using namespace std;
int main() {
    int first, k, n, sum = 0;
    cin >> first >> n >> k;
    int temp, data[100005], next[100005], list[100005], result[100005];
    for (int i = 0; i < n; i++) {
        cin >> temp;
        cin >> data[temp] >> next[temp];
    }
    while (first != -1) {
        list[sum++] = first;
        first = next[first];
    }
    for (int i = 0; i < sum; i++) result[i] = list[i];
    for (int i = 0; i < (sum - sum % k); i++)//只翻转能构成k个的部分 
        result[i] = list[i / k * k + k - 1 - i % k];//完全可以用公式完成分组翻转赋值 
    for (int i = 0; i < sum - 1; i++)
        printf("%05d %d %05d\n", result[i], data[result[i]], result[i + 1]);
    printf("%05d %d -1", result[sum - 1], data[result[sum - 1]]);
    return 0;
}
