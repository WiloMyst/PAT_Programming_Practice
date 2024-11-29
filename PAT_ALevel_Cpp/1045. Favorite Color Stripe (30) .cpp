#include <iostream>//记录每个喜欢的颜色在喜欢序列中的位置，位置构成升序序列，book[i]=j表示i颜色的位置为j。
#include <vector>  //先在输入的时候剔除不在喜欢序列中的元素，然后把剩余元素转成位置保存在数组a中，基于位置按照最长不下降子序列的方式做。 
using namespace std;
int book[201], a[10001], dp[10001];//dp[]为以i位置结尾的最长不下降子序列长度 
int main() {
    int n, m, x, l, num = 0, maxn = 0;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        scanf("%d", &x);
        book[x] = i;
    }
    scanf("%d", &l);
    for(int i = 0; i < l; i++) {
        scanf("%d", &x);
        if(book[x] >= 1)
            a[num++] = book[x];//喜欢的颜色转成位置存下来 
    }
    for(int i = 0; i < num; i++) {//对位置构成的序列求最长不下降子序列长度 
        dp[i] = 1;
        for(int j = 0; j < i; j++)
            if(a[i] >= a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        maxn = max(dp[i], maxn);
    }
    printf("%d", maxn);
    return 0;
}

//out of ...  从...中 
