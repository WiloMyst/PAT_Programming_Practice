#include <cstdio>
#include <algorithm>
using namespace std;
struct info {
    int id, fid, mid, num, area;
    int cid[10];
}info[1005];
struct node {
    int id, people;
    double num, area;
    bool flag = false;
}ans[10000];
int father[10000];
bool visit[10000];//id是否存在 
int find(int x) {
    int a = x;
    while(x != father[x])//根结点的父亲是自身 
        x = father[x];
    while(a != father[a]) {
        int t = a;
        a = father[a];
        father[t] = x;
    }
    return x;
}
void Union(int a, int b) {
    int faA = find(a);
    int faB = find(b);
    if(faA > faB)//合并时让id小的作为根结点 
        father[faA] = faB;
    else if(faA < faB)
        father[faB] = faA;
}
int cmp1(node a, node b) {
    if(a.area != b.area)
        return a.area > b.area;
    else
        return a.id < b.id;
}
int main() {
    int n, k, cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < 10000; i++)
        father[i] = i;
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &info[i].id, &info[i].fid, &info[i].mid, &k);
        visit[info[i].id] = true;
        if(info[i].fid != -1) {
            visit[info[i].fid] = true;
            Union(info[i].fid, info[i].id);
        }
        if(info[i].mid != -1) {
            visit[info[i].mid] = true;
            Union(info[i].mid, info[i].id);
        }
        for(int j = 0; j < k; j++) {
            scanf("%d", &info[i].cid[j]);
            visit[info[i].cid[j]] = true;
            Union(info[i].cid[j], info[i].id);
        }
        scanf("%d %d", &info[i].num, &info[i].area);
    }
    for(int i = 0; i < n; i++) {
        int id = find(info[i].id);//找到其根结点id 
        ans[id].id = id;
        ans[id].num += info[i].num;
        ans[id].area += info[i].area;
        ans[id].flag = true;//是根结点 
    }
    for(int i = 0; i < 10000; i++) {
        if(visit[i])
            ans[find(i)].people++;
    }
    for(int i = 0; i < 10000; i++) {
        if(ans[i].flag) {
            cnt++;
            ans[i].num = ans[i].num / ans[i].people;
            ans[i].area = ans[i].area / ans[i].people;
        }
    }
    sort(ans, ans + 10000, cmp1);//直接重排结果哈希表 
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++)
        printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].people, ans[i].num, ans[i].area);
    return 0;
}

//sets of 套 
