#include <iostream>
#include <vector>
using namespace std;
struct node {
    int v;
    struct node *left, *right;
};
node* build(node *root, int v) {//递归构建二叉排序树 
    if(root == NULL) {
        root = new node();
        root->v = v;
        root->left = root->right = NULL;
    } else if(v <= root->v)
        root->left = build(root->left, v);//如果不写赋值式就会断链(实参形参是两个不同的指针变量) 
    else
        root->right = build(root->right, v);
    return root;
}
vector<int> num(1000);
int maxdepth = -1;
void dfs(node *root, int depth) {
    if(root == NULL) {
        maxdepth = max(depth, maxdepth);
        return ;
    }
    num[depth]++;
    dfs(root->left, depth + 1);
    dfs(root->right, depth + 1);
    
}
int main() {
    int n, t;
    scanf("%d", &n);
    node *root = NULL;
    for(int i = 0; i < n; i++) {
        scanf("%d", &t);
        root = build(root, t);
    }
    dfs(root, 0);
    printf("%d + %d = %d", num[maxdepth-1], num[maxdepth-2], num[maxdepth-1] + num[maxdepth-2]);
    return 0;
}
