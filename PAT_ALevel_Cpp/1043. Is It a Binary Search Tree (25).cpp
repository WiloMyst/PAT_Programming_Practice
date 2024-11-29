#include <cstdio>//二叉排序树不需要中序序列也可进行序列转换，因为可通过结点值与当前root的大小关系划分左右子树。 
#include <vector>
using namespace std;//首先分解求后序遍历结果的过程：求出左子树的后序遍历结果，求出右子树后序遍历的结果，将当前子树的根结点加入后序遍历的结果中去。 
bool isMirror;
vector<int> pre, post;
void getpost(int root, int tail) {
    if(root > tail) return ;
    int i = root + 1, j = tail;
    if(!isMirror) {
        while(i <= tail && pre[root] > pre[i]) i++;//由左小右大的性质代替中序序列分出左右子树 
        while(j > root && pre[root] <= pre[j]) j--;
    } else {
        while(i <= tail && pre[root] <= pre[i]) i++;
        while(j > root && pre[root] > pre[j]) j--;
    }
    if(i - j != 1) return ;//如果i-j!=1，表明该子序列不是先序序列 
    getpost(root + 1, j);
    getpost(i, tail);
    post.push_back(pre[root]);//生成后序序列 
}
int main() {
    int n;
    scanf("%d", &n);
    pre.resize(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    getpost(0, n - 1);
    if(post.size() != n) {//若不是先序序列会导致后序序列长度不对(少了) 
        isMirror = true;
        post.clear();
        getpost(0, n - 1);
    }
    if(post.size() == n) {
        printf("YES\n%d", post[0]);
        for(int i = 1; i < n; i++)
            printf(" %d", post[i]);
    } else {
        printf("NO");
    }
    return 0;
}

//is recursively defined 递归定义的 
