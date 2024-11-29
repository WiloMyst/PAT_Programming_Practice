#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct node {
    int poptime, endtime;//ÿ�����л����ڵ�һ���˺����һ���˵��뿪ʱ�� 
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
    vector<bool> sorry(k + 1, false);//������龡������map 
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
    while(index <= k) {//�����ʣ��������ѭ����indexָ������ӵ��Ǹ��� 
        int tempmin = window[1].poptime, tempwindow = 1;
        for(int i = 2; i <= n; i++) {//ÿ�δӶ���1��ʼȷ��һ�����뿪 
            if(window[i].poptime < tempmin) {
                tempwindow = i;
                tempmin = window[i].poptime;
            }
        }
        window[tempwindow].q.pop();
        window[tempwindow].q.push(time[index]);//indexָ�����˽��� 
        window[tempwindow].poptime += window[tempwindow].q.front();
        if(window[tempwindow].endtime >= 540)//ע��ϸ�ڣ������17��ǰ������17���δ�����꣬��ʱҲҪ��ӡʱ�䡣����endtime�������к�� 
            sorry[index] = true;             //17��֮����ţ�����17����� 
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
