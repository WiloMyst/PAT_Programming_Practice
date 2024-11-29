#include <iostream>//Dijkstra算法需要dis[]和visit[]数组 
#include <algorithm>
using namespace std;
int n, m, c1, c2;
//邻接矩阵/点权(各城市救援队数)/从起点到i最短路径长度/从起点到i最短路径条数/从起点到i救援队数目之和 
int e[510][510], weight[510], dis[510], num[510], w[510];
bool visit[510];
const int inf = 99999999;//无穷大设置：1.不能用0x7fffffff，因为涉及无穷大加法会溢出。2.可用0x3fffffff，10^9量级，且满足两∞相加不溢出。3.可用0x3f3f3f3f，10^9量级，且满足两∞相加不溢出，且便于按字节初始化memset(arr, 0x3f, sizeof(arr)) 
int main() {
    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    for(int i = 0; i < n; i++)
        scanf("%d", &weight[i]);
    fill(e[0], e[0] + 510 * 510, inf);//二维数组初始化：e[0]代表第0行首元素地址，步长为一个元素，而二维数组可视作一个大的一维数组。(不能用e作为参数，否则步长变为一行) 
    fill(dis, dis + 510, inf); 
    int a, b, c;
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        e[a][b] = e[b][a] = c;
    }
    dis[c1] = 0;
    w[c1] = weight[c1];
    num[c1] = 1;
    for(int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for(int j = 0; j < n; j++) {//找到未访问的顶点中dis[]最小的(首次是c1) 
            if(visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;//找不到小于inf的dis[]，说明剩下的顶点与起点不连通 
        visit[u] = true;//定下顶点的dis[] 
        for(int v = 0; v < n; v++) {//基于定下的u进行其余顶点dis[]优化 
            if(visit[v] == false && e[u][v] != inf) {
                if(dis[u] + e[u][v] < dis[v]) {//若经u到v路径更短 
                    dis[v] = dis[u] + e[u][v];
                    num[v] = num[u];//v的最短路数应改为u的最短路数 
                    w[v] = w[u] + weight[v];
                } else if(dis[u] + e[u][v] == dis[v]) {//若等长 
                    num[v] = num[v] + num[u];//v的最短路数应加上u的最短路数
                    if(w[u] + weight[v] > w[v])
                        w[v] = w[u] + weight[v];
                }
            }
        }
    }
    printf("%d %d", num[c2], w[c2]);
    return 0;
}

/* 二维数组各种指针的含义： (https://blog.csdn.net/Lemon_jay/article/details/83007589)
	a代表第0行的首地址，其步长为一行的长度；
	&a[i]代表第i行首地址，等价于a+i；
	*a代表第0行第0个元素的地址，其步长为一个元素的长度；
	a[i]代表第i行首元素地址，等价于*(a+i)； 
	&a代表整个二维数组的首地址，其步长为一个二维数组的大小；
	*(a+i)+j代表第i行第j列元素的地址；
	&a[i][j]代表第i行第j列元素的地址，等价于*(a+i)+j；
	*(*(a+i)+j)比*(a+i)+j外面多个*，代表第i行第j列元素的值,等价于a[i][j]； 
	PS：&a与a (&a[0])与*a (a[0])的值一样，但代表意义不同，实质是步长不同 
*/

//emergency rescue 紧急救援
