#include <iostream>
#include <algorithm>
using namespace std;
int Data[100005], Next[100005], list[100005];
int main() {
    int first, k, n, temp;	//地址可以当整型处理 
    cin >> first >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        cin >> Data[temp] >> Next[temp];	//链表结点的所在地址和存储数据的映射关系一般不会变 
    }
    int sum = 0;
    while (first != -1) {
        list[sum++] = first;
        first = Next[first];
    }
    for (int i = 0; i < (sum - sum % k); i += k)
        reverse(list + i, list + i + k);	//直接翻转排好后的结点地址即可，这样每个地址的后一个地址就是Next 
    for (int i = 0; i < sum - 1; i++)
        printf("%05d %d %05d\n", list[i], Data[list[i]], list[i + 1]);
    printf("%05d %d -1\n", list[sum - 1], Data[list[sum - 1]]);
    return 0;
}
