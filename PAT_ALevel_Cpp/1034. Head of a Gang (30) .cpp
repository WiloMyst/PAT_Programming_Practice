#include <iostream>//总的来说是判断一个图的连通分量的个数，用图的遍历解决，深度优先遍历
#include <map>     //如果一个团伙人数超过2人并且通话总权值超过k，令团伙里面的自身权值的最大值为头目，输出所有满足条件的团伙的头目，和他们团伙里面的人数 
using namespace std;
map<string, int> stringToInt;//名字转数字 
map<int, string> intToString;//数字转名字 
map<string, int> ans;//map存答案，自动按字典序排序 
int idNumber = 1, k;
int stoifunc(string s) {
    if(stringToInt[s] == 0) {
        stringToInt[s] = idNumber;
        intToString[idNumber] = s;
        return idNumber++;
    } else {
        return stringToInt[s];
    }
}
int G[2010][2010], weight[2010];//边权和点权 
bool vis[2010];//visit数组 
void dfs(int u, int &head, int &numMember, int &totalweight) {//引用参数来返回值 
    vis[u] = true;
    numMember++;
    if(weight[u] > weight[head])
        head = u;
    for(int v = 1; v < idNumber; v++) {
        if(G[u][v] > 0) {//注意，这里的条件不能是边存在&&点未访问，否则只能统计DFS树上的边权。这种条件统计连通分量上总边权 
            totalweight += G[u][v];
            G[u][v] = G[v][u] = 0;//统计后就删该边，防止边权被重复统计 
            if(vis[v] == false)
                dfs(v, head, numMember, totalweight);
        }
    }
}
void dfsTrave() {
    for(int i = 1; i < idNumber; i++) {
        if(vis[i] == false) {
            int head = i, numMember = 0, totalweight = 0;
            dfs(i, head, numMember, totalweight);
            if(numMember > 2 && totalweight > k)
                ans[intToString[head]] = numMember;
        }
    }
}
int main() {
    int n, w;
    cin >> n >> k;
    string s1, s2;
    for(int i = 0; i < n; i++) {
        cin >> s1 >> s2 >> w;
        int id1 = stoifunc(s1);
        int id2 = stoifunc(s2);
        weight[id1] += w;
        weight[id2] += w;
        G[id1][id2] += w;
        G[id2][id1] += w;
    }
    dfsTrave();
    cout << ans.size() << endl;
    for(auto it = ans.begin(); it != ans.end(); it++)
        cout << it->first << " " << it->second << endl;
    return 0;
}

//threshold 阈值，门槛 
