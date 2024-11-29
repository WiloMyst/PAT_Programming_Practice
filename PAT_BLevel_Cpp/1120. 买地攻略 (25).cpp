#include <iostream>
using namespace std;
int N, M, ans, a, pre[10005];
int main(){
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> a;
        pre[i] = pre[i - 1] + a;//记录该位置及其前面的标价之和 
    }
    for (int i = 1; i <= N; i++) 
        for (int j = i; j <= N && pre[j] - pre[i - 1] <= M; j++) 
            ans++;
    cout << ans;
    return 0;
}
