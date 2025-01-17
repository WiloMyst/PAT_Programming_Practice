#include <iostream>//动态规划，01背包(各元素怎么选使得总额最大的问题)
#include <vector>
#include <algorithm>
using namespace std;
int dp[10010], w[10010];//dp[i][j]表示前i个面值任意取装入总面值容量为j的包中所能获得的最大面值 
bool choice[10010][110];//choice[i][j]记录计算dp[i][j]时选没选该硬币(同位置标记数组) 
int cmp1(int a, int b){return a > b;}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    sort(w + 1, w + n + 1, cmp1);//倒序排序，使最后倒推选出硬币时能获得字典序正序 
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= w[i]; j--) {
            if(dp[j] <= dp[j-w[i]] + w[i]) {//若选和不选总面值等大，应当选，因为选面值更小的确保答案字典序最小 
                choice[i][j] = true;
                dp[j] = dp[j-w[i]] + w[i];
            }
        }
    }
    if(dp[m] != m) printf("No Solution");//最大面值总额没达到m 
    else {
        vector<int> arr;
        int v = m, index = n;
        while(v > 0) {
            if(choice[index][v] == true) {//利用choice[][]数组从[n][m]倒推出选取的硬币(对大部分动态规划问题，输出方案的方法都是：记录每一步选择了哪个策略，然后从最终态倒着推出) 
                arr.push_back(w[index]);//arr存的就是字典序最小序列 
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
