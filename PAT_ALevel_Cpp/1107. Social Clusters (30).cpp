#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> father, isRoot;
int cmp1(int a, int b){return a > b;}
int findFather(int x) {//������ ������x��father 
    int a = x;
    while(x != father[x])//���ҵ�����father 
        x = father[x];
    while(a != father[a]) {//����һ�Σ�����;�����Ľ���father�ĳ�����father 
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;//��������father 
}
void Union(int a, int b) {//���ϲ� ������a��fatherΪb��father 
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB) father[faA] = faB;//���ڡ����� ��ʱ�м������ߵĹ��̣����ȡһ����father���� 
}
int main() {//��"������"�������ƣ����A��B�Ǻ����ѣ�B��C�Ǻ����ѣ���ôA��C���Ǻ����ѣ������Aѡ��1��2�Σ�Bѡ��1�Σ�Cѡ��2�Σ���ôA��B��C����ͬһ��cluster�е���
    int n, k, t, cnt = 0;//��������Ҫ����һ��Ԫ�ص���������ʱ������Ҫ�ò��鼯����set�ǲ���� 
    int course[1001] = {0};
    scanf("%d", &n);
    father.resize(n + 1);//���鼯�洢�ṹ 
    isRoot.resize(n + 1);
    for(int i = 1; i <= n; i++)//���鼯��ʼ�� 
        father[i] = i;
    for(int i = 1; i <= n; i++) {
        scanf("%d:", &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &t);
            if(course[t] == 0)//course[t] == 0 ����֮ǰû���˰���t 
                course[t] = i;
            Union(i, findFather(course[t]));
        }
    }
    for(int i = 1; i <= n; i++)
        isRoot[findFather(i)]++;//�洢���������ж���Ԫ�أ��������ǵĸ����ɢ�м��� 
    for(int i = 1; i <= n; i++) {
        if(isRoot[i] != 0) cnt++;
    }
    printf("%d\n", cnt);
    sort(isRoot.begin(), isRoot.end(), cmp1);
    for(int i = 0; i < cnt; i++) {
        printf("%d", isRoot[i]);
        if(i != cnt - 1) printf(" ");
    }
    return 0;
}
