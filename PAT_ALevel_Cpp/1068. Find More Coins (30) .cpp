#include <iostream>//��̬�滮��01����(��Ԫ����ôѡʹ���ܶ���������)
#include <vector>
#include <algorithm>
using namespace std;
int dp[10010], w[10010];//dp[i][j]��ʾǰi����ֵ����ȡװ������ֵ����Ϊj�İ������ܻ�õ������ֵ 
bool choice[10010][110];//choice[i][j]��¼����dp[i][j]ʱѡûѡ��Ӳ��(ͬλ�ñ������) 
int cmp1(int a, int b){return a > b;}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    sort(w + 1, w + n + 1, cmp1);//��������ʹ�����ѡ��Ӳ��ʱ�ܻ���ֵ������� 
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= w[i]; j--) {
            if(dp[j] <= dp[j-w[i]] + w[i]) {//��ѡ�Ͳ�ѡ����ֵ�ȴ�Ӧ��ѡ����Ϊѡ��ֵ��С��ȷ�����ֵ�����С 
                choice[i][j] = true;
                dp[j] = dp[j-w[i]] + w[i];
            }
        }
    }
    if(dp[m] != m) printf("No Solution");//�����ֵ�ܶ�û�ﵽm 
    else {
        vector<int> arr;
        int v = m, index = n;
        while(v > 0) {
            if(choice[index][v] == true) {//����choice[][]�����[n][m]���Ƴ�ѡȡ��Ӳ��(�Դ󲿷ֶ�̬�滮���⣬��������ķ������ǣ���¼ÿһ��ѡ�����ĸ����ԣ�Ȼ�������̬�����Ƴ�) 
                arr.push_back(w[index]);//arr��ľ����ֵ�����С���� 
                v -= w[index];
            }
            index--;
        }
        for(int i = 0; i < arr.size(); i++) {
            if(i != 0) printf(" ");
            printf("%d", arr[i]);
        }
    }
    return 0;
}
