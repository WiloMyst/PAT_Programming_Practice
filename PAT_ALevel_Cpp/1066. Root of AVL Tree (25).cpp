#include <iostream>
using namespace std;
struct node {
    int val;
    struct node *left, *right;
};
node *rotateL(node *root) {//������д 
    node *t = root->right;
    root->right = t->left;//���Կ���">""\"��������ṹ�Ĳ�����һ���ġ�(����">"����Ҫ��һ�����ӻ�����) 
    t->left = root;
    return t;
}
node *rotateR(node *root) {
    node *t = root->left;
    root->left = t->right;
    t->right = root;
    return t;
}
node *rotateLR(node *root) {//˫����Ҫ�õ����� 
    root->left = rotateL(root->left);
    return rotateR(root);
}
node *rotateRL(node *root) {
    root->right = rotateR(root->right);
    return rotateL(root);
}
int getHeight(node *root) {//�ݹ������� 
    if(root == NULL) return 0;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}
node *insert(node *root, int val) {
    if(root == NULL) {
        root = new node();//�½�node����ָ��ָ�� 
        root->val = val;
        root->left = root->right = NULL;
    } else if(val < root->val) {
        root->left = insert(root->left, val);
        if(getHeight(root->left) - getHeight(root->right) == 2)//���ı߲壬�ı߲ſ������� 
            root = val < root->left->val ? rotateR(root) : rotateLR(root);//����ֱ���޸ĵ�ǰָ���ַ��д���ǳ�����ֵ��ѧϰ��rootҪ����ָ��ǰ����ָ�룬��Ҫ������ǰ��㡣 
    } else {
        root->right = insert(root->right, val);
        if(getHeight(root->left) - getHeight(root->right) == -2)
            root = val > root->right->val ? rotateL(root) : rotateRL(root);//�������ҵ��ң���ǰ������һ�Σ��������ҵ�������������һ�ε�ǰ������һ�Ρ� 
    }
    return root;//���ظ�����ַ 
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

//restore this property �ָ���һ���� 
