#include <iostream>//���ж��Ƿ���clique�����ж��Ƿ��������߶�������֮���ж��Ƿ���maximal�����������в��ڼ����е�ʣ��ĵ㣬���Ƿ����һ��������ͼ��������еĽ������
#include <vector>
using namespace std;
int e[210][210];//�ڽӾ��� 
int main() {
    int nv, ne, m, ta, tb, k;
    scanf("%d %d", &nv, &ne);
    for (int i = 0; i < ne; i++) {
        scanf("%d %d", &ta, &tb);
        e[ta][tb] = e[tb][ta] = 1;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &k);
        vector<int> v(k);//�㼯(��) 
        int hash[210] = {0}, isclique = 1, isMaximal = 1;
        for (int j = 0; j < k; j++) {
            scanf("%d", &v[j]);
            hash[v[j]] = 1;
        }
        for (int j = 0; j < k; j++) {
            if (isclique == 0) break;
            for (int l = j + 1; l < k; l++) {
                if (e[v[j]][v[l]] == 0) {
                    isclique = 0;
                    printf("Not a Clique\n");
                    break;
                }
            }
        }
        if (isclique == 0) continue;
        for (int j = 1; j <= nv; j++) {
            if (hash[j] == 0) {
                for (int l = 0; l < k; l++) {
                    if (e[v[l]][j] == 0) break;
                    if (l == k - 1) isMaximal = 0;//������һ��������ͼ��������еĽ����������������š��˴�д��ֵ��ѧϰ 
                }
            }
            if (isMaximal == 0) {
                printf("Not Maximal\n");
                break;
            }
        }
        if (isMaximal == 1) printf("Yes\n");
    }
    return 0;
}

//clique �� 
//subset �Ӽ�
//graph theory ͼ�� 
