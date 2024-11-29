#include <cstdio>//��άBFS��"��"���⡣����һ����ά���飬0��ʾ���� 1��ʾ��������������Ĵ�С>=t��������������������������������Ĵ�С
#include <queue> //���⵱���е�Ϊ1ʱ��DFS�ᱬջ 
using namespace std;
struct node {//���껯���㣬Ϊ����װ����� 
    int x, y, z;
};
int m, n, l, t;
int X[6] = {1, 0, 0, -1, 0, 0};//��ά�������飬���� 
int Y[6] = {0, 1, 0, 0, -1, 0};
int Z[6] = {0, 0, 1, 0, 0, -1};
int arr[1300][130][80];
bool inq[1300][130][80];//�Ƿ������ 
bool judge(int x, int y, int z) {//judge�ж��Ƿ񳬹��˱߽磬�����Ƿ�ǰ���Ϊ0��������
    if(x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= l) return false;
    if(arr[x][y][z] == 0 || inq[x][y][z] == true) return false;
    return true;
}
int bfs(int x, int y, int z) {
    int cnt = 0;
    node temp;
    temp.x = x, temp.y = y, temp.z = z;
    queue<node> q;
    q.push(temp);
    inq[x][y][z] = true;
    while(!q.empty()) {
        node top = q.front();//ȡ���� 
        q.pop();
        cnt++;//���Գ���ʱͳ�� 
        for(int i = 0; i < 6; i++) {//���6��������ڵ� 
            int tx = top.x + X[i];
            int ty = top.y + Y[i];
            int tz = top.z + Z[i];
            if(judge(tx, ty, tz)) {
                temp.x = tx, temp.y = ty, temp.z = tz;
                q.push(temp);
                inq[tx][ty][tz] = true;
            }
        }
    }
    if(cnt >= t)
        return cnt;
    else
        return 0;
}
int main() {
    scanf("%d %d %d %d", &m, &n, &l, &t);
    for(int i = 0; i < l; i++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k < n; k++)
                scanf("%d", &arr[j][k][i]);
    int ans = 0;
    for(int i = 0; i < l; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < n; k++) {
                if(arr[j][k][i] == 1 && inq[j][k][i] == false)
                    ans += bfs(j, k, i);
            }
        }
    }
    printf("%d", ans);
    return 0;
}
