#include <cstdio>
using namespace std;
struct NODE {
    char key;
    int next;
    bool flag;//增加一域，表示是否被访问过 
}node[100000];
int main() {
    int s1, s2, n, a, b;
    scanf("%d%d%d", &s1, &s2, &n);
    char data;
    for(int i = 0; i < n; i++) {
        scanf("%d %c %d", &a, &data, &b);
        node[a] = {data, b, false};
    }
    for(int i = s1; i != -1; i = node[i].next)//遍历链表的写法 
        node[i].flag = true;
    for(int i = s2; i != -1; i = node[i].next) {
        if(node[i].flag == true) {//发现在链表1中已被访问，表明有公共结点 
            printf("%05d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}

//sublist 子列表
//e.g. 例如 
