#include <iostream>//DFS + ��֦��������ֱ��k��ѭ�������⣬ʱ�临�ӶȻ����� 
#include <vector>
#include <cmath>
using namespace std;
int n, k, p, maxFacSum = -1;
vector<int> v, ans, tempAns;
void init() {//�Ȱ�i��0��ʼ���е�i��p�η���ֵ�洢��v[i]�У�ֱ��v[i] > nΪֹ
    int temp = 0, index = 1;
    while (temp <= n) {
        v.push_back(temp);
        temp = pow(index, p);
        index++;
    }
}
void dfs(int index, int tempSum, int tempK, int facSum) {
    if (tempK == k) {//tempk��0~k-1���ﵽk����жϲ�ֹͣ�����ݹ�(��֦)
        if (tempSum == n && facSum > maxFacSum) {
            ans = tempAns;
            maxFacSum = facSum;//������Ӻ� 
        }
        return; 
    }
    while(index >= 1) {
        if (tempSum + v[index] <= n) {//�ۼ�֮�ͳ���nҲҪֹͣ�����ݹ�(��֦) 
            tempAns[tempK] = index;
            dfs(index, tempSum + v[index], tempK + 1, facSum + index);
        }
        index--;
    }
}
int main() {
    scanf("%d%d%d", &n, &k, &p);
    init(); 
    tempAns.resize(k);
    dfs(v.size() - 1, 0, 0, 0);//��v[i]�����һ��index��ʼһֱ��index == 1����Ϊ�������ܱ�֤ans��tempAns�������汣����ǴӴ�С�����ӵ�˳��
    if (maxFacSum == -1) {
        printf("Impossible");
        return 0;
    }
    printf("%d = ", n);
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) printf(" + ");
        printf("%d^%d", ans[i], p);
    }
    return 0;
}

//factorization ���ӷֽ�
// P-th power P���� 
