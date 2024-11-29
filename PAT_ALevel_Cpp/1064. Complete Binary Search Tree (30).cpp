#include <iostream>
#include <algorithm>
using namespace std;
int in[1010], level[1010], n, t = 0;
void inOrder(int root) {//设根结点完全编号为0，中序遍历"完全编号树"(对应位置为对应完全二叉树结点编号的虚拟树，这个过程是没有实树的) (原理是先中后遍历时一定能得到下一个结点的完全编号)
    if (root >= n) return ;
    inOrder(root * 2 + 1);
    level[root] = in[t++];//每中序遍历到一个结点，就把它的关键字值in[t]存入层序序列中的层序标号处 
    inOrder(root * 2 + 2);
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &in[i]);
    sort(in, in + n);
    inOrder(0);//设根结点完全编号为0
    printf("%d", level[0]);
    for (int i = 1; i < n; i++)
        printf(" %d", level[i]);
    return 0;
}

//Complete Binary Tree (CBT) 完全二叉树
//Binary Search Tree (BST) 二叉排序树 
