#include <iostream>//本题要求输出能构成最高树的所有根结点 
#include <vector>  //该问题有这一解法：进行2次DFS。第一次任取顶点DFS，记下所有最深叶结点；第二次任取一最深叶结点DFS，记下所有最深叶结点。两次所得最深叶结点取并集即为所求。 
#include <set>     //事实上相当于，第一次DFS得到所有最长路径的一端顶点，第二次DFS得到另一端顶点。 
#include <algorithm>
using namespace std;
int n, maxheight = 0;
vector<vector<int>> v;//邻接表 (邻接矩阵会超时) 
bool visit[10010];
set<int> s;//存最深叶结点
vector<int> temp;//DFS中暂存最深叶结点 
void dfs(int node, int height) {
    if(height > maxheight) {
        temp.clear();
        temp.push_back(node);
        maxheight = height;
    } else if(height == maxheight){
        temp.push_back(node);
    }
    visit[node] = true;
    for(int i = 0; i < v[node].size(); i++) {
        if(visit[v[node][i]] == false)
            dfs(v[node][i], height + 1);
    }
}
int main() {
    scanf("%d", &n);
    v.resize(n + 1);
    int a, b, cnt = 0, s1 = 0;
    for(int i = 0; i < n - 1; i++) {//输入只有n-1条边，因此只可能是树或非连通图。(显然n-1条边不能使连通图构成环) 
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) {//第一次DFS，同时记录连通分量数 
        if(visit[i] == false) {
            dfs(i, 1);
            if(i == 1) {//第二个连通分量没必要做 
                if (temp.size() != 0) s1 = temp[0];
                for(int j = 0; j < temp.size(); j++)
                    s.insert(temp[j]);
            }
            cnt++;
        }
    }
    if(cnt >= 2) {
        printf("Error: %d components", cnt);
    } else {//第二次DFS 
        temp.clear();
        maxheight = 0;
        fill(visit, visit + 10010, false);
        dfs(s1, 1);
        for(int i = 0; i < temp.size(); i++)
            s.insert(temp[i]);//求并集可以直接用set<>代替 
        for(auto it = s.begin(); it != s.end(); it++)
            printf("%d\n", *it);
    }
    return 0;
}

//acyclic 非循环的  cyclic 循环的
//connected component 连通分量 
