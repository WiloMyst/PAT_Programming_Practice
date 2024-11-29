#include <iostream>//找出一条路线，使得对任何给定的起点和终点，可以找出中途经停站最少的路线；如果经停站一样多，则取需要换乘线路次数最少的路线
#include <vector>  //除了BFS类算法(BFS、Dijkstra)，DFS在有效剪枝情况下也可以求最短路问题(如地铁线路图这种岔路少的图) 
#include <unordered_map>
using namespace std;
vector<vector<int>> v(10000);//邻接表，直接用4位id。(她把边上的信息另用一个umap存储) 
int visit[10000], minCnt, minTransfer, start, end1;
unordered_map<int, int> line;//边信息。line[][]数组转成umap保存每两个相邻站中间的线路是几号线，否则会爆内存(化二维为一维，化数组为umap) 
vector<int> path, tempPath;
int transferCnt(vector<int> a) {//要处理初始情况，因此要写函数单独求解 
    int cnt = -1, preLine = 0;//preLine为前一小段的线路编号，如果当前的结点和前一个结点组成的这条路的线路编号和preLine不同，说明有一个换乘，就将cnt+1，cnt即是换乘的次数 
    for (int i = 1; i < a.size(); i++) {
        if (line[a[i-1]*10000+a[i]] != preLine) cnt++;
        preLine = line[a[i-1]*10000+a[i]];
    }
    return cnt;
}
void dfs(int node, int cnt) {//这里的cnt表示当前路线是所需乘的第几个站，每次dfs时候将cnt+1表示向下遍历一层，cnt就是当前中途停站的次数
    if (node == end1 && (cnt < minCnt || (cnt == minCnt && transferCnt(tempPath) < minTransfer))) {
        minCnt = cnt;
        minTransfer = transferCnt(tempPath);
        path = tempPath;
    }
    if (node == end1) return;//剪枝 
    for (int i = 0; i < v[node].size(); i++) {
        if (visit[v[node][i]] == 0) {
            visit[v[node][i]] = 1;
            tempPath.push_back(v[node][i]);
            dfs(v[node][i], cnt + 1);
            visit[v[node][i]] = 0;//DFS求最短路时返回要把visit归0，因为之后的路线仍可能经过该点(只需实现不走回头路，不需实现仅单次访问) 
            tempPath.pop_back();
        }
    }
}
int main() {
    int n, m, k, pre, temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &m, &pre);//先读一个作为pre 
        for (int j = 1; j < m; j++) {
            scanf("%d", &temp);
            v[pre].push_back(temp);
            v[temp].push_back(pre);
            line[pre*10000+temp] = line[temp*10000+pre] = i + 1;//保存每两个相邻站中间的线路是几号线，值得学习 
            pre = temp;
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &start, &end1);
        minCnt = 99999, minTransfer = 99999;//minCnt-中途经停的最少的站; minTransfer-需要换乘的最小次数 
        tempPath.clear();
        tempPath.push_back(start);
        visit[start] = 1;
        dfs(start, 0);//不涉及边权，不需要Dijkstra 
        visit[start] = 0;
        printf("%d\n", minCnt);
        int preLine = 0, preTransfer = start;
        for (int j = 1; j < path.size(); j++) {
            if (line[path[j-1]*10000+path[j]] != preLine) {
                if (preLine != 0) printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, path[j-1]);//要处理初始情况 
                preLine = line[path[j-1]*10000+path[j]];
                preTransfer = path[j-1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, end1);
    }
    return 0;
}

//self-loop 自回路(不经过其他点的回路) 
//sample map 示例地图
//transfer station 中转站，改线站 
