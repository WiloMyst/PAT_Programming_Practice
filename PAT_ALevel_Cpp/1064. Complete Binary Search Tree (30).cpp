#include <iostream>
#include <algorithm>
using namespace std;
int in[1010], level[1010], n, t = 0;
void inOrder(int root) {//��������ȫ���Ϊ0���������"��ȫ�����"(��Ӧλ��Ϊ��Ӧ��ȫ����������ŵ������������������û��ʵ����) (ԭ�������к����ʱһ���ܵõ���һ��������ȫ���)
    if (root >= n) return ;
    inOrder(root * 2 + 1);
    level[root] = in[t++];//ÿ���������һ����㣬�Ͱ����Ĺؼ���ֵin[t]������������еĲ����Ŵ� 
    inOrder(root * 2 + 2);
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &in[i]);
    sort(in, in + n);
    inOrder(0);//��������ȫ���Ϊ0
    printf("%d", level[0]);
    for (int i = 1; i < n; i++)
        printf(" %d", level[i]);
    return 0;
}

//Complete Binary Tree (CBT) ��ȫ������
//Binary Search Tree (BST) ���������� 
