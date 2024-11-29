#include <iostream>
#include <map>
using namespace std;
int n, In[32];
map<int, int> ans;
void deal(int index, int L, int R) {//dfs + 层序标号传送 
    if (L > R) return;
    int pos = L;
    for (int i = L + 1; i <= R; i++)
        if (In[i] < In[pos]) pos = i;//找到中序片段里值最小的那个位置（根结点） 
    ans[index] = In[pos];//把当前最小值放到答案层序标号处（妙，map自动有序且忽略空缺位置） 
    deal(index << 1, L, pos - 1);
    deal(index << 1 | 1, pos + 1, R);
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> In[i];
    deal(1, 0, n - 1);
    for (auto it : ans) {
        if (it.first != 1) cout << ' ';
        cout << it.second;
    }
    return 0;
}

//Cartesian tree 笛卡尔树
//heap-ordered 堆有序的 
