#include <iostream>
#include <algorithm>
using namespace std;
struct NODE {
    int address, key, next;
    bool flag;
}node[100000];
int cmp1(NODE a, NODE b) {
    return !a.flag || !b.flag ? a.flag > b.flag : a.key < b.key;
}
int main() {
    int n, cnt = 0, s, a, b, c;
    scanf("%d%d", &n, &s);
    for(int i = 0; i < n; i++) {
        scanf("%d%d%d", &a, &b, &c);
        node[a] = {a, b, c, false};
    }
    for(int i = s; i != -1; i = node[i].next) {
        node[i].flag = true;
        cnt++;
    }
    if(cnt == 0) {//一定要用cnt重新计数，因为不一定所有输入结点都在链表上
        printf("0 -1");
    } else {
        sort(node, node + 100000, cmp1);
        printf("%d %05d\n", cnt, node[0].address);
        for(int i = 0; i < cnt; i++) {
            printf("%05d %d ", node[i].address, node[i].key);
            if(i != cnt - 1)
                printf("%05d\n", node[i + 1].address);
            else
                printf("-1\n");
        }
    }
    return 0;
}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//struct NODE {
//    int key, next;
//}node[100010];
//int cmp1(int a, int b) {
//    return node[a].key < node[b].key;
//}
//int main() {
//    int n, s, a, b, c, i = 0;
//    scanf("%d%d", &n, &s);
//    vector<int> v;
//    for(i = 0; i < n; i++) {
//        scanf("%d%d%d", &a, &b, &c);
//        node[a] = {b, c};
//    }
//    for(i = s; i != -1; i = node[i].next)
//        v.push_back(i);
//    if(v.size() == 0) {//一定要用v.size()，因为不一定所有输入结点都在链表上 
//        printf("0 -1");
//    } else {
//        sort(v.begin(), v.end(), cmp1);
//        printf("%d %05d\n", v.size(), v[0]);
//        for(i = 0; i < v.size() - 1; i++)
//            printf("%05d %d %05d\n", v[i], node[v[i]].key, v[i + 1]);
//        printf("%05d %d -1\n", v[i], node[v[i]].key);
//    }
//    return 0;
//}
