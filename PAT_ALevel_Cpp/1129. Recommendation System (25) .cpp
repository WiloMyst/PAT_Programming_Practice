#include <iostream>
#include <set>
using namespace std;
int book[50001];
struct node {
    int value, cnt;
    friend bool operator < (const node &a, const node &b) {//定义set对node的自排序规则，set不能用sort()，只能重载运算符 
        return (b.cnt != a.cnt) ? a.cnt > b.cnt : a.value < b.value;
    }
};
int main() {
    int n, k, num;
    scanf("%d%d", &n, &k);
    set<node> s;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        if (i != 0) {
            printf("%d:", num);
            int tempCnt = 0;
            for(auto it = s.begin(); tempCnt < k && it != s.end(); it++) {
                printf(" %d", it->value);
                tempCnt++;
            }
            printf("\n");
        }
        auto it = s.find(node{num, book[num]});
        if (it != s.end()) s.erase(it);//删除是因为要更新它的cnt（set中的元素会自动排序，且不能直接修改它的元素值） 
        book[num]++;
        s.insert(node{num, book[num]});
    }
    return 0;
}

//indices 索引，指数(复数形式) 
//tie 平局 
