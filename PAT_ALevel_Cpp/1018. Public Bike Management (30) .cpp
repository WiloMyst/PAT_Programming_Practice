#include <iostream>//���һ����վ���������Ļ��߿յģ��������ģ����ڽ��0�����ͻ�Я�����ߴ�·���ռ�һ�����������г�ǰ���ó�վ��һ·�ϻ������еĳ�վ��;���ﵽ���������ڸ���cmax����վ������n�����⳵վsp��m���ߣ����о��룬�����·����������·���ж�������ܴ������ٵ����г���Ŀ����������������кܶ�����ͬ��·����ô����һ���ӳ�վ���ص����г���Ŀ���ٵģ����ص�ʱ���ǲ������ģ�
#include <algorithm>//ע�⣡������ʱ��������Ҳ����˵���涥�������ĳ������ṩ��ǰ�涥�㣡(��needֻ������) 
#include <vector>
using namespace std;
const int inf = 99999999;//��0x3fffffff 
int cmax, n, sp, m;
int minNeed = inf, minBack = inf;
int e[510][510], dis[510], weight[510];
bool visit[510];
vector<int> pre[510], path, temppath;//pre[]Ϊ���·����ǰ������(Dijkstra��·������) 
void dfs(int v) {//����pre������path��minNeed��minBack��ע��path�Ƿ���(�ݹ�����spΪ�������ΪҶ����) 
    temppath.push_back(v);
    if(v == 0) {//����������� 
        int need = 0, back = 0;
        for(int j = temppath.size() - 1; j >= 0; j--) {
            back += weight[temppath[j]];
            if(back < 0) {//back������С��0��˵����Ҫ�ṩ���ˡ�back��0 
                need += -back;
                back = 0;
            }
        }
        if(need < minNeed) {
            minNeed = need;
            minBack = back;
            path = temppath;//vector��ֱ�����帲�� 
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
        weight[i] = weight[i] - cmax / 2;//��Ȩ��Ϊweight-cmax/2 (��㲻�ģ���0) 
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
        if(u == -1) break;//���޿ɴ�δ���ʵ� 
        visit[u] = true;
        for(int v = 0; v <= n; v++) {
            if(visit[v] == false && e[u][v] != inf) {
                if(dis[v] > dis[u] + e[u][v]) {
                    dis[v] = dis[u] + e[u][v];
                    pre[v].clear();//���¼�¼v�����·ǰ�� 
                    pre[v].push_back(u);//u�����·����v��ǰ�� 
                } else if(dis[v] == dis[u] + e[u][v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
    dfs(sp);//ֻ��Dijkstra�ǲ����Եģ���ΪminNeed��minBack��·���ϵĴ��ݲ����������ӽṹ�����Ǽ򵥵���ӵĹ��̣�ֻ��������·����ȷ����֮�������ѡ����С��need����С��back
    printf("%d 0", minNeed);
    for(int i = path.size() - 2; i >= 0; i--)
        printf("->%d", path[i]);
    printf(" %d", minBack);
    return 0;
}

/* ���·��������·��
	���������������ӽṹ��Dijkstra��������⼴�� 
	�����ⲻ���������ӽṹ��Dijkstra��pre���� + DFS����pre���������·ʱ��� 
*/ 

//exactly half-full ���ð��� 
