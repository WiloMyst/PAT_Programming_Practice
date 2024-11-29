#include <iostream>
#include <vector>
using namespace std;
int V, E, K, Start, End, a, b, d;
int Edge[1002][1002], dis[1002], flag, visit[1002];
void deal(int x, int index, vector<int> Path) {
    for(int k = 1; k <= V; k++) {
        int Min = 9999999, now = Path[index];
        for(int i = 1; i <= V; i++) {
            if(dis[i] != 9999999 && !visit[i] && dis[i] <= Min) {
                if(dis[i] < Min) {
                    if(i == now) flag = 1;
                    else flag = 0;
                } else if(dis[i] == Min) {
                    if(i == now) flag = 1;
                }
                Min = dis[i];
            }
        }
        if(!flag) return;
        ++index;
//        if(index > V) return;
        visit[now] = 1;
        for(int i = 1; i <= V; i++) 
            if(!visit[i] && dis[i] > dis[now] + Edge[now][i] && Edge[now][i] != 0) 
                dis[i] = dis[now] + Edge[now][i];
    }
}
int main() {
    cin >> V >> E;
    for(int i = 0; i < E; i++) {
        cin >> a >> b >> d;
        Edge[a][b] = Edge[b][a] = d;
    }
    cin >> K;
    for(int i = 0; i < K; i++) {
        vector<int> Path(V);
        flag = 1;
        fill(visit, visit + 1002, 0);
        fill(dis, dis + 1002, 9999999);
        for(int j = 0; j < V; j++) cin >> Path[j];
        Start = Path[0], End = Path[V - 1];
        dis[Start] = 0;
        deal(Start, 0, Path);
        if(flag) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
