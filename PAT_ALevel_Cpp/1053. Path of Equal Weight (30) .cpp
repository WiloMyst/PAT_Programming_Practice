#include <iostream>//greater<>和less<>包含在里面 
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 110;
struct node {
    int weight;
    vector<int> child;
} Node[maxn];
int n, m, s;
vector<int> path; //路径
vector<vector<int> > ans; //存放所有路径，(">"间加空格防止C++11标准前的编译器视为移位操作)
void DFS(int index, int sum) {
    if (sum > s) return;
    if (sum == s) {
        if (Node[index].child.size() != 0) return; //还未到叶子结点
        ans.push_back(path);
        return;
    }
    for (int i = 0; i < Node[index].child.size(); i++) {
        int child = Node[index].child[i];
        path.push_back(Node[child].weight);
        DFS(child, sum + Node[child].weight);
        path.pop_back();//删除vector末尾元素 
    }
}
int main() {
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 0; i < n; i++)
        scanf("%d", &Node[i].weight);
    int id, k, child;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &id, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &child);
            Node[id].child.push_back(child);
        }
    }
    path.push_back(Node[0].weight);
    DFS(0, Node[0].weight);
    //对所有路径按字典序从大到小排序greater<vector<int> >() 
    sort(ans.begin(), ans.end(), greater<vector<int> >());//注意，另一种想法，输入阶段对每个结点的孩子按权重从大到小排序，是错的。因为对于值相同的两个孩子，它们的孩子之间不一定字典降序，从而导致前者产生的路径字典序可能小于后者。 
    for (int i = 0; i < ans.size(); i++) {
        printf("%d", ans[i][0]);
        for (int j = 1; j < ans[i].size(); j++)
            printf(" %d", ans[i][j]);
        printf("\n");
    }
    return 0;
}
