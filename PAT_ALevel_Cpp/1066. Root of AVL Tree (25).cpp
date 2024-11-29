#include <iostream>
using namespace std;
struct node {
    int val;
    struct node *left, *right;
};
node *rotateL(node *root) {//单旋先写 
    node *t = root->right;
    root->right = t->left;//可以看到">""\"两种三点结构的操作是一样的。(尽管">"形需要给一个孩子换父亲) 
    t->left = root;
    return t;
}
node *rotateR(node *root) {
    node *t = root->left;
    root->left = t->right;
    t->right = root;
    return t;
}
node *rotateLR(node *root) {//双旋需要用到单旋 
    root->left = rotateL(root->left);
    return rotateR(root);
}
node *rotateRL(node *root) {
    root->right = rotateR(root->right);
    return rotateL(root);
}
int getHeight(node *root) {//递归求树高 
    if(root == NULL) return 0;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}
node *insert(node *root, int val) {
    if(root == NULL) {
        root = new node();//新建node结点给指针指向 
        root->val = val;
        root->left = root->right = NULL;
    } else if(val < root->val) {
        root->left = insert(root->left, val);
        if(getHeight(root->left) - getHeight(root->right) == 2)//往哪边插，哪边才可能增高 
            root = val < root->left->val ? rotateR(root) : rotateLR(root);//这种直接修改当前指针地址的写法非常清晰值得学习。root要看作指向当前结点的指针，不要看作当前结点。 
    } else {
        root->right = insert(root->right, val);
        if(getHeight(root->left) - getHeight(root->right) == -2)
            root = val > root->right->val ? rotateL(root) : rotateRL(root);//若插在右的右，当前树左旋一次；若插在右的左，右子树右旋一次当前树左旋一次。 
    }
    return root;//返回根结点地址 
}
int main() {
    int n, val;
    scanf("%d", &n);
    node *root = NULL;
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("%d", root->val);
    return 0;
}

//restore this property 恢复这一特性 
