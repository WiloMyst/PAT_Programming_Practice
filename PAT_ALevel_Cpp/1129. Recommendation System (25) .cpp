#include <iostream>
#include <set>
using namespace std;
int book[50001];
struct node {
    int value, cnt;
    friend bool operator < (const node &a, const node &b) {//����set��node�����������set������sort()��ֻ����������� 
        return (b.cnt != a.cnt) ? a.cnt > b.cnt : a.value < b.value;
    }
};
int main() {
    int n, k, num;
    scanf("%d%d", &n, &k);
    set<node> s;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        if (i != 0) {
            printf("%d:", num);
            int tempCnt = 0;
            for(auto it = s.begin(); tempCnt < k && it != s.end(); it++) {
                printf(" %d", it->value);
                tempCnt++;
            }
            printf("\n");
        }
        auto it = s.find(node{num, book[num]});
        if (it != s.end()) s.erase(it);//ɾ������ΪҪ��������cnt��set�е�Ԫ�ػ��Զ������Ҳ���ֱ���޸�����Ԫ��ֵ�� 
        book[num]++;
        s.insert(node{num, book[num]});
    }
    return 0;
}

//indices ������ָ��(������ʽ) 
//tie ƽ�� 
