#include <cstdio>
#include <algorithm>
using namespace std;
int v[1010][1010];//邻接矩阵，顶点数不超过1000可用 
bool visit[1010];//图遍历比树遍历多一个visit数组 
int n;
void dfs(int node) {
    visit[node] = true;
    for(int i = 1; i <= n; i++) {
        if(visit[i] == false && v[node][i] == 1)//边存在且点未访问 
            dfs(i);
    }
}
int main() {
    int m, k, a, b;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        v[a][b] = v[b][a] = 1;
    }
    for(int i = 0; i < k; i++) {
        fill(visit, visit + 1010, false);//初始化填充函数 
        scanf("%d", &a);
        int cnt = 0;
        visit[a] = true;//去除这个城市结点，就是把它标记为已经访问过
        for(int j = 1; j <= n; j++) {
            if(visit[j] == false) {
                dfs(j);
                cnt++;
            }
        }
        printf("%d\n", cnt - 1);
    }
    return 0;
}
