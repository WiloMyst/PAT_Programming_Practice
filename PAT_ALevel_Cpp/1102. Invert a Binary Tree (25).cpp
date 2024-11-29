#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    int id, l, r, index, level;
} a[100];
vector<node> v1;
void dfs(int root, int index, int level) {
    if (a[root].r != -1) dfs(a[root].r, index * 2 + 2, level + 1);
    v1.push_back({root, 0, 0, index, level});
    if (a[root].l != -1) dfs(a[root].l, index * 2 + 1, level + 1);
}
bool cmp(node a, node b) {//根据深度和层序标号排成层序序列 
    if (a.level != b.level) return a.level < b.level;
    return a.index > b.index;
}
int main() {
    int n, have[100] = {0}, root = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        a[i].id = i;
        string l, r;
        cin >> l >> r;
        if (l != "-") {
            a[i].l = stoi(l);
            have[stoi(l)] = 1;
        } else {
            a[i].l = -1;
        }
        if (r != "-") {
            a[i].r = stoi(r);
            have[stoi(r)] = 1;
        } else {
            a[i].r = -1;
        }
    }
    while (have[root] == 1) root++;//注意本题没说明根结点。0~n-1中未成为其他结点的孩子的结点就是根结点。 
    dfs(root, 0, 0);
    vector<node> v2(v1);//用已有容器初始化容器 
    sort(v2.begin(), v2.end(), cmp);
    for (int i = 0; i < v2.size(); i++) {
        if (i != 0) cout << " ";
        cout << v2[i].id;
    }
    cout << endl;
    for (int i = 0; i < v1.size(); i++) {
        if (i != 0) cout << " ";
        cout << v1[i].id;
    }
    return 0;
}

//invert 反转 
