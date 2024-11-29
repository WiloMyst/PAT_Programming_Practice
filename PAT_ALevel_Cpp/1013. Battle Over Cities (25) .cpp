#include <cstdio>
#include <algorithm>
using namespace std;
int v[1010][1010];//�ڽӾ��󣬶�����������1000���� 
bool visit[1010];//ͼ��������������һ��visit���� 
int n;
void dfs(int node) {
    visit[node] = true;
    for(int i = 1; i <= n; i++) {
        if(visit[i] == false && v[node][i] == 1)//�ߴ����ҵ�δ���� 
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
        fill(visit, visit + 1010, false);//��ʼ����亯�� 
        scanf("%d", &a);
        int cnt = 0;
        visit[a] = true;//ȥ��������н�㣬���ǰ������Ϊ�Ѿ����ʹ�
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
