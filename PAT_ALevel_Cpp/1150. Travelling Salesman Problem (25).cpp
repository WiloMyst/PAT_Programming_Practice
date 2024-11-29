#include <iostream>//如果给出的路径存在某两个连续的点不可达或者第一个结点和最后一个结点不同或者这个路径没有访问过图中所有的点，那么它就不是一个旅行商环路(flag = 0)。如果满足了旅行商环路的条件，那么再判断这个旅行商环路是否是简单旅行商环路，即是否访问过n+1个结点（源点访问两次）
#include <vector>
#include <set>
using namespace std;
int e[300][300], n, m, k, ans = 99999999, ansid;//无穷大可以设为0x3f3f3f3f，也是10^9量级，并且满足无穷大+无穷大=无穷大 
vector<int> v;
void check(int index) {
    int sum = 0, cnt, flag = 1;
    scanf("%d", &cnt);
    set<int> s;//用于检查路径是否访问所有顶点 
    vector<int> v(cnt);//存测试路径 
    for (int i = 0; i < cnt; i++) {
        scanf("%d", &v[i]);
        s.insert(v[i]);
    }
    for (int i = 0; i < cnt - 1; i++) {
        if(e[v[i]][v[i+1]] == 0) flag = 0;
        sum += e[v[i]][v[i+1]];
    }
    if (flag == 0) {
        printf("Path %d: NA (Not a TS cycle)\n", index);
    } else if(v[0] != v[cnt-1] || s.size() != n) {
        printf("Path %d: %d (Not a TS cycle)\n", index, sum);
    } else if(cnt != n + 1) {//路长为n+1才可能是简单TS回路 
        printf("Path %d: %d (TS cycle)\n", index, sum);
        if (sum < ans) {
            ans = sum;
            ansid = index;
        }
    } else {
        printf("Path %d: %d (TS simple cycle)\n", index, sum);
        if (sum < ans) {
            ans = sum;
            ansid = index;
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int t1, t2, t;
        scanf("%d%d%d", &t1, &t2, &t);
        e[t1][t2] = e[t2][t1] = t;
    }
    scanf("%d", &k);
    for (int i = 1; i <= k; i++) check(i);
    printf("Shortest Dist(%d) = %d\n", ansid, ans);
    return 0;
}

//combinatorial optimization 组合优化
//operations research 运筹学
//theoretical computer science 理论计算机科学 
