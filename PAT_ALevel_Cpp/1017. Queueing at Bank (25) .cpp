#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 10005;
struct person {
    int come, time;
} p[maxn];
int cmp(person p1, person p2) { return p1.come < p2.come; }
int n, k, cnt, total;
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        int hh, ss, mm, tt;
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &tt);
        int sum = hh * 3600 + mm * 60 + ss;
        if (sum > 61200) continue;
        p[++cnt].time = tt * 60;
        p[cnt].come = sum;
    }
    sort(p + 1, p + 1 + cnt, cmp);//按到达时间排序成等待队列 
    priority_queue<int, vector<int>, greater<int> > q;//<元素int型，底层存储结构，greater<int>小根堆/less<int>大根堆>。在各窗口服务结束时间中取最小的 
    for (int i = 1; i <= k; ++i) q.push(28800);//对于本题，服务结束时间等值时选哪个窗口不会影响结果 
    for (int i = 1; i <= cnt; ++i) {
        if (q.top() <= p[i].come) {
            q.push(p[i].come + p[i].time);
            q.pop();
        } else {
            total += q.top() - p[i].come;
            q.push(q.top() + p[i].time);
            q.pop();
        }
    }
    (!cnt) ? printf("0.0\n") : printf("%.1lf", ((double)total/60.0)/(double) cnt);
    return 0;
}
