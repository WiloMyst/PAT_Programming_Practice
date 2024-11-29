#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m, k, nv, a, b, num;
    scanf("%d%d", &n, &m);
    vector<int> v[n];
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        v[a].push_back(i);//v[a]记录包含顶点a的边的序号i 
        v[b].push_back(i);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &nv);
        int flag = 0;
        vector<int> hash(m, 0);
        for (int j = 0; j < nv; j++) {
            scanf("%d", &num);
            for (int t = 0; t < v[num].size(); t++)
                hash[v[num][t]] = 1;//将该顶点涉及的边打上标记 
        }
        for (int j = 0; j < m; j++) {
            if (hash[j] == 0) {//只要有一条边没被打标记，就不满足顶点覆盖 
                printf("No\n");
                flag = 1;
                break;
            }
        }
        if (flag == 0) printf("Yes\n");
    }
    return 0;
}
