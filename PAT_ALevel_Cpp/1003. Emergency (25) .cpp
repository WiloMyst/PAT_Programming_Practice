#include <iostream>//Dijkstra�㷨��Ҫdis[]��visit[]���� 
#include <algorithm>
using namespace std;
int n, m, c1, c2;
//�ڽӾ���/��Ȩ(�����о�Ԯ����)/����㵽i���·������/����㵽i���·������/����㵽i��Ԯ����Ŀ֮�� 
int e[510][510], weight[510], dis[510], num[510], w[510];
bool visit[510];
const int inf = 99999999;//��������ã�1.������0x7fffffff����Ϊ�漰�����ӷ��������2.����0x3fffffff��10^9������������������Ӳ������3.����0x3f3f3f3f��10^9������������������Ӳ�������ұ��ڰ��ֽڳ�ʼ��memset(arr, 0x3f, sizeof(arr)) 
int main() {
    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    for(int i = 0; i < n; i++)
        scanf("%d", &weight[i]);
    fill(e[0], e[0] + 510 * 510, inf);//��ά�����ʼ����e[0]�����0����Ԫ�ص�ַ������Ϊһ��Ԫ�أ�����ά���������һ�����һά���顣(������e��Ϊ���������򲽳���Ϊһ��) 
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
        for(int j = 0; j < n; j++) {//�ҵ�δ���ʵĶ�����dis[]��С��(�״���c1) 
            if(visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;//�Ҳ���С��inf��dis[]��˵��ʣ�µĶ�������㲻��ͨ 
        visit[u] = true;//���¶����dis[] 
        for(int v = 0; v < n; v++) {//���ڶ��µ�u�������ඥ��dis[]�Ż� 
            if(visit[v] == false && e[u][v] != inf) {
                if(dis[u] + e[u][v] < dis[v]) {//����u��v·������ 
                    dis[v] = dis[u] + e[u][v];
                    num[v] = num[u];//v�����·��Ӧ��Ϊu�����·�� 
                    w[v] = w[u] + weight[v];
                } else if(dis[u] + e[u][v] == dis[v]) {//���ȳ� 
                    num[v] = num[v] + num[u];//v�����·��Ӧ����u�����·��
                    if(w[u] + weight[v] > w[v])
                        w[v] = w[u] + weight[v];
                }
            }
        }
    }
    printf("%d %d", num[c2], w[c2]);
    return 0;
}

/* ��ά�������ָ��ĺ��壺 (https://blog.csdn.net/Lemon_jay/article/details/83007589)
	a�����0�е��׵�ַ���䲽��Ϊһ�еĳ��ȣ�
	&a[i]�����i���׵�ַ���ȼ���a+i��
	*a�����0�е�0��Ԫ�صĵ�ַ���䲽��Ϊһ��Ԫ�صĳ��ȣ�
	a[i]�����i����Ԫ�ص�ַ���ȼ���*(a+i)�� 
	&a����������ά������׵�ַ���䲽��Ϊһ����ά����Ĵ�С��
	*(a+i)+j�����i�е�j��Ԫ�صĵ�ַ��
	&a[i][j]�����i�е�j��Ԫ�صĵ�ַ���ȼ���*(a+i)+j��
	*(*(a+i)+j)��*(a+i)+j������*�������i�е�j��Ԫ�ص�ֵ,�ȼ���a[i][j]�� 
	PS��&a��a (&a[0])��*a (a[0])��ֵһ�������������岻ͬ��ʵ���ǲ�����ͬ 
*/

//emergency rescue ������Ԯ
