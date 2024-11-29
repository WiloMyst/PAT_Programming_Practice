#include <iostream>
using namespace std;
int a[1005], m, n;
void postOrder(int index) {
    if (index > n) return;
    postOrder(index * 2);
    postOrder(index * 2 + 1);
    printf("%d%s", a[index], index == 1 ? "\n" : " ");//最后的根结点后输出回车 
}
int main() {
    scanf("%d %d", &m, &n);
    while (m--) {
        int minn = 1, maxn = 1;
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 2; i <= n; i++) {//写法太妙了，从1开始编号，当前结点标号整除2一定是父亲结点标号 
            if (a[i] > a[i / 2]) maxn = 0;
            if (a[i] < a[i / 2]) minn = 0;
        }
        if (maxn == 1) printf("Max Heap\n");
        else if (minn == 1) printf("Min Heap\n");
        else printf("Not Heap\n");
        postOrder(1);
    }
    return 0;
}

//specialized 专门的 
//binary heap 二叉堆 
