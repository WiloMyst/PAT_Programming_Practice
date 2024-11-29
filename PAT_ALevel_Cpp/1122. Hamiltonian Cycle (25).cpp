#include <iostream>//设置flag1，判断节点是否多走、少走、或走成环
#include <set>     //设置flag2，判断这条路能不能走通
#include <vector>  //当flag1、flag2都为1时是哈密尔顿路径，否则不是
using namespace std;
int main() {
    int n, m, cnt, k, a[210][210] = {0};
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int t1, t2;
        scanf("%d%d", &t1, &t2);
        a[t1][t2] = a[t2][t1] = 1;
    }
    cin >> cnt;
    while(cnt--) {
        cin >> k;
        vector<int> v(k);
        set<int> s;
        int flag1 = 1, flag2 = 1;
        for(int i = 0; i < k; i++) {
            scanf("%d", &v[i]);
            s.insert(v[i]);
        }
        if(s.size() != n || k - 1 != n || v[0] != v[k-1]) flag1 = 0;//是否走过所有点 || 路长是否为n+1 || 首尾顶点是否一致 
        for(int i = 0; i < k - 1; i++)
            if(a[v[i]][v[i+1]] == 0) flag2 = 0;//邻接矩阵判断边的存在性更容易 
        printf("%s",flag1 && flag2 ? "YES\n" : "NO\n");
    }
    return 0;
}

//simple cycle 简单回路 
//undirected graph 无向图
//directed graph 有向图
//Vi's  (Vi的复数形式) 
