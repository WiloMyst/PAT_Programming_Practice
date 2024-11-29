#include <cstdio>//��������������Ҫ��������Ҳ�ɽ�������ת������Ϊ��ͨ�����ֵ�뵱ǰroot�Ĵ�С��ϵ�������������� 
#include <vector>
using namespace std;//���ȷֽ�������������Ĺ��̣�����������ĺ����������������������������Ľ��������ǰ�����ĸ��������������Ľ����ȥ�� 
bool isMirror;
vector<int> pre, post;
void getpost(int root, int tail) {
    if(root > tail) return ;
    int i = root + 1, j = tail;
    if(!isMirror) {
        while(i <= tail && pre[root] > pre[i]) i++;//����С�Ҵ�����ʴ����������зֳ��������� 
        while(j > root && pre[root] <= pre[j]) j--;
    } else {
        while(i <= tail && pre[root] <= pre[i]) i++;
        while(j > root && pre[root] > pre[j]) j--;
    }
    if(i - j != 1) return ;//���i-j!=1�������������в����������� 
    getpost(root + 1, j);
    getpost(i, tail);
    post.push_back(pre[root]);//���ɺ������� 
}
int main() {
    int n;
    scanf("%d", &n);
    pre.resize(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    getpost(0, n - 1);
    if(post.size() != n) {//�������������лᵼ�º������г��Ȳ���(����) 
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

//is recursively defined �ݹ鶨��� 
