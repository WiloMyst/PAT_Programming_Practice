#include <iostream>//如果一个车站容量是满的或者空的，控制中心（处于结点0处）就会携带或者从路上收集一定数量的自行车前往该车站，一路上会让所有的车站沿途都达到完美。现在给出cmax，车站的数量n，问题车站sp，m条边，还有距离，求最短路径。如果最短路径有多个，求能带的最少的自行车数目的那条。如果还是有很多条不同的路，那么就找一个从车站带回的自行车数目最少的（带回的时候是不调整的）
#include <algorithm>//注意！往回走时不调整，也就是说后面顶点多出来的车不会提供给前面顶点！(即need只增不减) 
#include <vector>
using namespace std;
const int inf = 99999999;//或0x3fffffff 
int cmax, n, sp, m;
int minNeed = inf, minBack = inf;
int e[510][510], dis[510], weight[510];
bool visit[510];
vector<int> pre[510], path, temppath;//pre[]为最短路顶点前驱数组(Dijkstra记路径方法) 
void dfs(int v) {//深搜pre数组求path和minNeed和minBack，注意path是反的(递归树是sp为根、起点为叶的树) 
    temppath.push_back(v);
    if(v == 0) {//到达起点才求解 
        int need = 0, back = 0;
        for(int j = temppath.size() - 1; j >= 0; j--) {
            back += weight[temppath[j]];
            if(back < 0) {//back被减到小于0，说明需要提供车了。back归0 
                need += -back;
                back = 0;
            }
        }
        if(need < minNeed) {
            minNeed = need;
            minBack = back;
            path = temppath;//vector可直接整体覆盖 
        } else if(need == minNeed && back < minBack) {
            minBack = back;
            path = temppath;
        }
        temppath.pop_back();
        return ;
    }
    for(int i = 0; i < pre[v].size(); i++)
        dfs(pre[v][i]);
    temppath.pop_back();
}
int main() {
    fill(e[0], e[0] + 510 * 510, inf);
    fill(dis, dis + 510, inf);
    scanf("%d%d%d%d", &cmax, &n, &sp, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &weight[i]);
        weight[i] = weight[i] - cmax / 2;//点权改为weight-cmax/2 (起点不改，置0) 
    }
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        scanf("%d", &e[a][b]);
        e[b][a] = e[a][b];
    }
    dis[0] = 0;
    for(int i = 0; i <= n; i++) {//Dijkstra 
        int u = -1, minn = inf;
        for(int j = 0; j <= n; j++) {
            if(visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;//已无可达未访问点 
        visit[u] = true;
        for(int v = 0; v <= n; v++) {
            if(visit[v] == false && e[u][v] != inf) {
                if(dis[v] > dis[u] + e[u][v]) {
                    dis[v] = dis[u] + e[u][v];
                    pre[v].clear();//重新记录v的最短路前驱 
                    pre[v].push_back(u);//u是最短路径上v的前驱 
                } else if(dis[v] == dis[u] + e[u][v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
    dfs(sp);//只有Dijkstra是不可以的，因为minNeed和minBack在路径上的传递不满足最优子结构，不是简单的相加的过程，只有在所有路径都确定了之后才能区选择最小的need和最小的back
    printf("%d 0", minNeed);
    for(int i = path.size() - 2; i >= 0; i--)
        printf("->%d", path[i]);
    printf(" %d", minBack);
    return 0;
}

/* 最短路类问题套路：
	若问题满足最优子结构：Dijkstra过程中求解即可 
	若问题不满足最优子结构：Dijkstra求pre数组 + DFS深搜pre至起点得最短路时求解 
*/ 

//exactly half-full 正好半满 
