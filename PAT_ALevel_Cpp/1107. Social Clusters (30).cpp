#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> father, isRoot;
int cmp1(int a, int b){return a > b;}
int findFather(int x) {//“查找 ”，找x的father 
    int a = x;
    while(x != father[x])//先找到最终father 
        x = father[x];
    while(a != father[a]) {//再找一次，把沿途经过的结点的father改成最终father 
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;//返回最终father 
}
void Union(int a, int b) {//“合并 ”，令a的father为b的father 
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB) father[faA] = faB;//由于“查找 ”时有减少树高的过程，随便取一方当father即可 
}
int main() {//和"好朋友"问题类似，如果A和B是好朋友，B和C是好朋友，那么A和C就是好朋友，即如果A选了1，2课，B选了1课，C选了2课，那么A，B，C就是同一个cluster中的人
    int n, k, t, cnt = 0;//当问题需要查找一个元素的所属集合时，就需要用并查集。用set是不便的 
    int course[1001] = {0};
    scanf("%d", &n);
    father.resize(n + 1);//并查集存储结构 
    isRoot.resize(n + 1);
    for(int i = 1; i <= n; i++)//并查集初始化 
        father[i] = i;
    for(int i = 1; i <= n; i++) {
        scanf("%d:", &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &t);
            if(course[t] == 0)//course[t] == 0 表明之前没有人爱好t 
                course[t] = i;
            Union(i, findFather(course[t]));
        }
    }
    for(int i = 1; i <= n; i++)
        isRoot[findFather(i)]++;//存储各个集合有多少元素，基于它们的根结点散列计数 
    for(int i = 1; i <= n; i++) {
        if(isRoot[i] != 0) cnt++;
    }
    printf("%d\n", cnt);
    sort(isRoot.begin(), isRoot.end(), cmp1);
    for(int i = 0; i < cnt; i++) {
        printf("%d", isRoot[i]);
        if(i != cnt - 1) printf(" ");
    }
    return 0;
}
