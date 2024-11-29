#include <iostream>//�ҳ�һ��·�ߣ�ʹ�ö��κθ����������յ㣬�����ҳ���;��ͣվ���ٵ�·�ߣ������ͣվһ���࣬��ȡ��Ҫ������·�������ٵ�·��
#include <vector>  //����BFS���㷨(BFS��Dijkstra)��DFS����Ч��֦�����Ҳ���������·����(�������·ͼ���ֲ�·�ٵ�ͼ) 
#include <unordered_map>
using namespace std;
vector<vector<int>> v(10000);//�ڽӱ�ֱ����4λid��(���ѱ��ϵ���Ϣ����һ��umap�洢) 
int visit[10000], minCnt, minTransfer, start, end1;
unordered_map<int, int> line;//����Ϣ��line[][]����ת��umap����ÿ��������վ�м����·�Ǽ����ߣ�����ᱬ�ڴ�(����άΪһά��������Ϊumap) 
vector<int> path, tempPath;
int transferCnt(vector<int> a) {//Ҫ�����ʼ��������Ҫд����������� 
    int cnt = -1, preLine = 0;//preLineΪǰһС�ε���·��ţ������ǰ�Ľ���ǰһ�������ɵ�����·����·��ź�preLine��ͬ��˵����һ�����ˣ��ͽ�cnt+1��cnt���ǻ��˵Ĵ��� 
    for (int i = 1; i < a.size(); i++) {
        if (line[a[i-1]*10000+a[i]] != preLine) cnt++;
        preLine = line[a[i-1]*10000+a[i]];
    }
    return cnt;
}
void dfs(int node, int cnt) {//�����cnt��ʾ��ǰ·��������˵ĵڼ���վ��ÿ��dfsʱ��cnt+1��ʾ���±���һ�㣬cnt���ǵ�ǰ��;ͣվ�Ĵ���
    if (node == end1 && (cnt < minCnt || (cnt == minCnt && transferCnt(tempPath) < minTransfer))) {
        minCnt = cnt;
        minTransfer = transferCnt(tempPath);
        path = tempPath;
    }
    if (node == end1) return;//��֦ 
    for (int i = 0; i < v[node].size(); i++) {
        if (visit[v[node][i]] == 0) {
            visit[v[node][i]] = 1;
            tempPath.push_back(v[node][i]);
            dfs(v[node][i], cnt + 1);
            visit[v[node][i]] = 0;//DFS�����·ʱ����Ҫ��visit��0����Ϊ֮���·���Կ��ܾ����õ�(ֻ��ʵ�ֲ��߻�ͷ·������ʵ�ֽ����η���) 
            tempPath.pop_back();
        }
    }
}
int main() {
    int n, m, k, pre, temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &m, &pre);//�ȶ�һ����Ϊpre 
        for (int j = 1; j < m; j++) {
            scanf("%d", &temp);
            v[pre].push_back(temp);
            v[temp].push_back(pre);
            line[pre*10000+temp] = line[temp*10000+pre] = i + 1;//����ÿ��������վ�м����·�Ǽ����ߣ�ֵ��ѧϰ 
            pre = temp;
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &start, &end1);
        minCnt = 99999, minTransfer = 99999;//minCnt-��;��ͣ�����ٵ�վ; minTransfer-��Ҫ���˵���С���� 
        tempPath.clear();
        tempPath.push_back(start);
        visit[start] = 1;
        dfs(start, 0);//���漰��Ȩ������ҪDijkstra 
        visit[start] = 0;
        printf("%d\n", minCnt);
        int preLine = 0, preTransfer = start;
        for (int j = 1; j < path.size(); j++) {
            if (line[path[j-1]*10000+path[j]] != preLine) {
                if (preLine != 0) printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, path[j-1]);//Ҫ�����ʼ��� 
                preLine = line[path[j-1]*10000+path[j]];
                preTransfer = path[j-1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, end1);
    }
    return 0;
}

//self-loop �Ի�·(������������Ļ�·) 
//sample map ʾ����ͼ
//transfer station ��תվ������վ 
