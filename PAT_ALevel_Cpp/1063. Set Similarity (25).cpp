#include <cstdio>
#include <vector>
#include <set>
using namespace std;
int main() {
    int n, m, k, temp, a, b;
    scanf("%d", &n);
    vector<set<int>> v(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &m);
        for(int j = 0; j < m; j++) {
            scanf("%d", &temp);
            v[i].insert(temp);
        }
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        scanf("%d %d", &a, &b);
        int nc = 0, nt = v[b-1].size();//妙，直接初始化不同数字总个数为集合b的大小 
        for(auto it = v[a-1].begin(); it != v[a-1].end(); it++) {
            if(v[b-1].find(*it) == v[b-1].end())
                nt++;
            else
                nc++;
        }
        double ans = (double)nc / nt * 100;
        printf("%.1f%%\n", ans);
    }
    return 0;
}
