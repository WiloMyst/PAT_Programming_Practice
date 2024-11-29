#include <cstdio>//三维BFS求"块"问题。给定一个三维数组，0表示正常 1表示有肿瘤，肿瘤块的大小>=t才算作是肿瘤，计算所有满足肿瘤块的大小
#include <queue> //本题当所有点为1时，DFS会爆栈 
using namespace std;
struct node {//坐标化作点，为了能装入队列 
    int x, y, z;
};
int m, n, l, t;
int X[6] = {1, 0, 0, -1, 0, 0};//三维增量数组，表方向 
int Y[6] = {0, 1, 0, 0, -1, 0};
int Z[6] = {0, 0, 1, 0, 0, -1};
int arr[1300][130][80];
bool inq[1300][130][80];//是否入过队 
bool judge(int x, int y, int z) {//judge判断是否超过了边界，或者是否当前结点为0不是肿瘤
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
        node top = q.front();//取队首 
        q.pop();
        cnt++;//可以出队时统计 
        for(int i = 0; i < 6; i++) {//检查6个方向的邻点 
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
