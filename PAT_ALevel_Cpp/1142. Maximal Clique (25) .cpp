#include <iostream>//先判断是否是clique，即判断是否任意两边都相连；之后判断是否是maximal，即遍历所有不在集合中的剩余的点，看是否存在一个点满足和集合中所有的结点相连
#include <vector>
using namespace std;
int e[210][210];//邻接矩阵 
int main() {
    int nv, ne, m, ta, tb, k;
    scanf("%d %d", &nv, &ne);
    for (int i = 0; i < ne; i++) {
        scanf("%d %d", &ta, &tb);
        e[ta][tb] = e[tb][ta] = 1;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &k);
        vector<int> v(k);//点集(团) 
        int hash[210] = {0}, isclique = 1, isMaximal = 1;
        for (int j = 0; j < k; j++) {
            scanf("%d", &v[j]);
            hash[v[j]] = 1;
        }
        for (int j = 0; j < k; j++) {
            if (isclique == 0) break;
            for (int l = j + 1; l < k; l++) {
                if (e[v[j]][v[l]] == 0) {
                    isclique = 0;
                    printf("Not a Clique\n");
                    break;
                }
            }
        }
        if (isclique == 0) continue;
        for (int j = 1; j <= nv; j++) {
            if (hash[j] == 0) {
                for (int l = 0; l < k; l++) {
                    if (e[v[l]][j] == 0) break;
                    if (l == k - 1) isMaximal = 0;//若存在一个点满足和集合中所有的结点相连，则不是最大团。此处写法值得学习 
                }
            }
            if (isMaximal == 0) {
                printf("Not Maximal\n");
                break;
            }
        }
        if (isMaximal == 1) printf("Yes\n");
    }
    return 0;
}

//clique 团 
//subset 子集
//graph theory 图论 
