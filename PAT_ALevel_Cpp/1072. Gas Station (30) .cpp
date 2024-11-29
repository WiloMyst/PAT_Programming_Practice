#include <iostream>//从m个加油站里面选取1个站点，让他离居民区的最近的人最远，并且没有超出服务范围ds之内。如果有很多个最远的加油站，输出距离所有居民区距离平均值最小的那个。如果平均值还是一样，就输出按照顺序排列加油站编号最小的那个
#include <algorithm>
#include <string>
using namespace std;
const int inf = 999999999;
int n, m, k, ds, station;
int e[1020][1020], dis[1020];
bool visit[1020];
int main() {
    fill(e[0], e[0] + 1020 * 1020, inf);
    fill(dis, dis + 1020, inf);
    scanf("%d%d%d%d", &n, &m, &k, &ds);
    for(int i = 0; i < k; i++) {
        int tempdis;
        string s, t;
        cin >> s >> t >> tempdis;
        int a, b;
        if(s[0] == 'G') {
            s = s.substr(1);
            a = n + stoi(s);
        } else {
            a = stoi(s);
        }
        if(t[0] == 'G') {
            t = t.substr(1);
            b = n + stoi(t);
        } else {
            b = stoi(t);
        }
        e[a][b] = e[b][a] = tempdis;
    }
    int ansid = -1;
    double ansdis = -1, ansaver = inf;
    for(int index = n + 1; index <= n + m; index++) {//检查每一个候选点 
        double mindis = inf, aver = 0;
        fill(dis, dis + 1020, inf);//dis和visit重置 
        fill(visit, visit + 1020, false);
        dis[index] = 0;
        for(int i = 0; i < n + m; i++) {
            int u = -1, minn = inf;
            for(int j = 1; j <= n + m; j++) {
                if(visit[j] == false && dis[j] < minn) {
                    u = j;
                    minn = dis[j];
                }
            }
            if(u == -1) break;
            visit[u] = true;
            for(int v = 1; v <= n + m; v++) {
                if(visit[v] == false && dis[v] > dis[u] + e[u][v])
                    dis[v] = dis[u] + e[u][v];
            }
        }
        for(int i = 1; i <= n; i++) {
            if(dis[i] > ds) {//超出服务范围 
                mindis = -1;
                break;
            }
            if(dis[i] < mindis) mindis = dis[i];//找到候选点和最近居民房的距离 
            aver += 1.0 * dis[i];
        }
        if(mindis == -1) continue;
        aver = aver / n;
        if(mindis > ansdis) {//需要让候选点和最近居民房的距离尽可能远 
            ansid = index;
            ansdis = mindis;
            ansaver = aver;
        } else if(mindis == ansdis && aver < ansaver) {
            ansid = index;
            ansaver = aver;
        }
    }
    if(ansid == -1)//ansid值仍非法，则解不存在 
        printf("No Solution");
    else
        printf("G%d\n%.1f %.1f", ansid - n, ansdis, ansaver);
    return 0;
}
