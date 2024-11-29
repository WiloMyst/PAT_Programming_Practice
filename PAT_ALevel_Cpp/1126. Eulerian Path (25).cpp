#include <iostream>//如果一个连通图的所有结点的度都是偶数，那么它就是Eulerian，如果除了两个结点的度是奇数其他都是偶数，那么它就是Semi-Eulerian，否则就是Non-Eulerian
#include <vector>
using namespace std;
vector<vector<int> > v;
vector<bool> visit;
int cnt = 0;
void dfs(int index) {//深搜判断连通性 
    visit[index] = true;
    cnt++;//遍历到的结点数 
    for (int i = 0; i < v[index].size(); i++)
        if (visit[v[index][i]] == false)
            dfs(v[index][i]);
}
int main() {
    int n, m, a, b, even = 0;
    scanf("%d%d", &n, &m);
    v.resize(n + 1);
    visit.resize(n + 1);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (i != 1) printf(" ");
        printf("%d", v[i].size());
        if (v[i].size() % 2 == 0) even++;
    }
    printf("\n");
    dfs(1);
    if (even == n && cnt == n)
        printf("Eulerian");
    else if(even == n - 2 && cnt == n)
        printf("Semi-Eulerian");
    else
        printf("Non-Eulerian");
    return 0;
}

//Eulerian circuit 欧拉回路 
