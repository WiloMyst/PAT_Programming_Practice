#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
vector<int> pre, in, post,value;
void postorder(int root, int start, int end) {
    if (start > end) return;
    int i = start;
    while (i < end && in[i] != pre[root]) i++;
    postorder(root + 1, start, i - 1);
    postorder(root + 1 + i - start, i + 1, end);
    post.push_back(pre[root]);
}
int main() {
    int n;
    scanf("%d", &n);
    char str[5];
    stack<int> s;
    int key=0;
    while (~scanf("%s", str)) {//scanf()的返回值为大于等于-1的数，只有当scanf()返回值为-1（二进制表示为全1）(EOF)时，~scanf()的值为0，其他情况均不为0
        if (strlen(str) == 4) {
            int num;
            scanf("%d", &num);
            value.push_back(num);
            pre.push_back(key);
            s.push(key++);
        } else {
            in.push_back(s.top());
            s.pop();
        }
    }
    postorder(0, 0, n - 1);
    printf("%d", value[post[0]]);
    for (int i = 1; i < n; i++)
        printf(" %d",value[post[i]]);
    return 0;
}

//implement 实现
//non-recursive way 非递归方式 

//#include <cstdio>
//#include <vector>
//#include <stack>
//#include <cstring>
//using namespace std;
//vector<int> pre, in, post;
//void postorder(int root, int start, int end) {
//    if (start > end) return;
//    int i = start;
//    while (i < end && in[i] != pre[root]) i++;
//    postorder(root + 1, start, i - 1);
//    postorder(root + 1 + i - start, i + 1, end);
//    post.push_back(pre[root]);
//}
//int main() {
//    int n;
//    scanf("%d", &n);
//    char str[5];
//    stack<int> s;
//    while (~scanf("%s", str)) {//scanf()的返回值为大于等于-1的数，只有当scanf()返回值为-1（二进制表示为全1）(EOF)时，~scanf()的值为0，其他情况均不为0
//        if (strlen(str) == 4) {
//            int num;
//            scanf("%d", &num);
//            pre.push_back(num);
//            s.push(num);
//        } else {
//            in.push_back(s.top());
//            s.pop();
//        }
//    }
//    postorder(0, 0, n - 1);
//    printf("%d", post[0]);
//    for (int i = 1; i < n; i++)
//        printf(" %d", post[i]);
//    return 0;
//}
