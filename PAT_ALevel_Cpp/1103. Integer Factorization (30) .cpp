#include <iostream>//DFS + 剪枝。不可以直接k层循环暴力解，时间复杂度会上天 
#include <vector>
#include <cmath>
using namespace std;
int n, k, p, maxFacSum = -1;
vector<int> v, ans, tempAns;
void init() {//先把i从0开始所有的i的p次方的值存储在v[i]中，直到v[i] > n为止
    int temp = 0, index = 1;
    while (temp <= n) {
        v.push_back(temp);
        temp = pow(index, p);
        index++;
    }
}
void dfs(int index, int tempSum, int tempK, int facSum) {
    if (tempK == k) {//tempk从0~k-1，达到k后就判断并停止继续递归(剪枝)
        if (tempSum == n && facSum > maxFacSum) {
            ans = tempAns;
            maxFacSum = facSum;//最大因子和 
        }
        return; 
    }
    while(index >= 1) {
        if (tempSum + v[index] <= n) {//累加之和超过n也要停止继续递归(剪枝) 
            tempAns[tempK] = index;
            dfs(index, tempSum + v[index], tempK + 1, facSum + index);
        }
        index--;
    }
}
int main() {
    scanf("%d%d%d", &n, &k, &p);
    init(); 
    tempAns.resize(k);
    dfs(v.size() - 1, 0, 0, 0);//从v[i]的最后一个index开始一直到index == 1，因为这样才能保证ans和tempAns数组里面保存的是从大到小的因子的顺序
    if (maxFacSum == -1) {
        printf("Impossible");
        return 0;
    }
    printf("%d = ", n);
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) printf(" + ");
        printf("%d^%d", ans[i], p);
    }
    return 0;
}

//factorization 因子分解
// P-th power P次幂 
