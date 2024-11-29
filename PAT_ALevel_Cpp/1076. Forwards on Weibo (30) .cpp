#include <cstdio>//给出每个用户关注的人的id，和转发最多的层数，求一个id发了条微博最多会有多少个人转发
#include <queue>
#include <vector>
using namespace std;
int n, l, m, k;
struct node {
    int id, layer;
};
vector<vector<int>> v;//邻接表。"关注"是有方向的，本题为有向图 
int bfs(node tnode) {
    bool inq[1010] = {false};//BFS中设置inq数组，表示是否入过队(而非表示是否被访问过的DFS的visit数组，因为在队列中但未被访问时仍可能再次进队) 
    queue<node> q;//注意STL的queue存的是原元素的副本，因此不能通过它修改原元素，尽量存元素信息 
    q.push(tnode);
    inq[tnode.id] = true;
    int cnt = 0;
    while(!q.empty()) {
        node top = q.front();
        q.pop();
        int topid = top.id;
        for(int i = 0; i < v[topid].size(); i++) {
            int nextid = v[topid][i];
            if(inq[nextid] == false && top.layer < l) {
                node next = {nextid, top.layer + 1};
                q.push(next);
                inq[next.id] = true;
                cnt++;
            }
        }
    }
    return cnt;
}
int main() {
    scanf("%d %d", &n, &l);
    v.resize(n + 1);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &m);
        for(int j = 0; j < m; j++) {
            int temp;
            scanf("%d", &temp);
            v[temp].push_back(i);//注意存的是粉丝，反着存 
        }
    }
    scanf("%d", &k);
    int tid;
    for(int i = 0; i < k; i++) {
        scanf("%d", &tid);
        node tnode = {tid, 0};//大括号赋值法 
        printf("%d\n", bfs(tnode));
    }
    return 0;
}

//forward  v.发送，转发 
//follow 关注，粉  follower 关注者，粉丝 
