#include <iostream>//动态规划，最大连续子序列和
#include <vector>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    int leftindex = 0, rightindex = n - 1, sum = -1, temp = 0, tempindex = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        temp = temp + v[i];
        if (temp < 0) {//temp = temp + v[i]，当temp比sum大，就更新sum的值、leftindex和rightindex的值；当temp < 0，那么后面不管来什么值，都应该舍弃temp < 0前面的内容，因为负数对于总和只可能拉低总和，不可能增加总和，还不如舍弃
            temp = 0;
            tempindex = i + 1;
        } else if (temp > sum) {
            sum = temp;
            leftindex = tempindex;
            rightindex = i;
        }
    }
    if (sum < 0) sum = 0;//妙，把sum当成flag，若存在>=0数字，则sum至少是>=0的 
    printf("%d %d %d", sum, v[leftindex], v[rightindex]);
    return 0;
}
