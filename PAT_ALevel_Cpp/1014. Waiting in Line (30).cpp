#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct node {
    int poptime, endtime;//每个队列黄线内第一个人和最后一个人的离开时间 
    queue<int> q;
};
int main() {
    int n, m, k, q, index = 1;
    scanf("%d%d%d%d", &n, &m, &k, &q);
    vector<int> time(k + 1), result(k + 1);
    for(int i = 1; i <= k; i++) {
        scanf("%d", &time[i]);
    }
    vector<node> window(n + 1);
    vector<bool> sorry(k + 1, false);//标记数组尽量不用map 
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(index <= k) {
                window[j].q.push(time[index]);
                if(window[j].endtime >= 540)
                    sorry[index] = true;
                window[j].endtime += time[index];
                if(i == 1)
                    window[j].poptime = window[j].endtime;
                result[index] = window[j].endtime;
                index++;
            }
        }
    }
    while(index <= k) {//会进行剩余人数次循环。index指代刚入队的那个人 
        int tempmin = window[1].poptime, tempwindow = 1;
        for(int i = 2; i <= n; i++) {//每次从队列1开始确定一个人离开 
            if(window[i].poptime < tempmin) {
                tempwindow = i;
                tempmin = window[i].poptime;
            }
        }
        window[tempwindow].q.pop();
        window[tempwindow].q.push(time[index]);//index指代的人进队 
        window[tempwindow].poptime += window[tempwindow].q.front();
        if(window[tempwindow].endtime >= 540)//注意细节，如果在17点前被服务但17点后未服务完，此时也要打印时间。所以endtime必须先判后改 
            sorry[index] = true;             //17点之后关门，而非17点关门 
        window[tempwindow].endtime += time[index];
        result[index] = window[tempwindow].endtime;
        index++;
    }
    for(int i = 1; i <= q; i++) {
        int query, minute;
        scanf("%d", &query);
        minute = result[query];
        if(sorry[query] == true) {
            printf("Sorry\n");
        } else {
            printf("%02d:%02d\n",(minute + 480) / 60, (minute + 480) % 60);
        }
    }
    return 0;
}
