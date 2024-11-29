#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
struct node {
    double data;//若为零售商，则为销售数量 
    vector<int> child;
};
vector<node> v;
double ans = 0.0, p, r;
void dfs(int index, int depth) {
    if(v[index].child.size() == 0) {
        ans += v[index].data * pow(1 + r, depth);//销售数量*增价倍数 
        return ;
    }
    for(int i = 0; i < v[index].child.size(); i++)
        dfs(v[index].child[i], depth + 1);
}
int main() {
    int n, k, c;
    scanf("%d %lf %lf", &n, &p, &r);
    r = r / 100;//注意给的是百分比 
    v.resize(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &k);
        if(k == 0) {
            scanf("%lf", &v[i].data);
        } else {
            for(int j = 0; j < k; j++) {
                scanf("%d", &c);
                v[i].child.push_back(c);
            }
        }
    }
    dfs(0, 0);
    printf("%.1f", ans * p);//总销售金额 
    return 0;
}

// the unit price 单价 
// then instead 则 
// the total amount of the product 产品总量 
