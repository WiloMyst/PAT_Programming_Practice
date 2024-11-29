#include <iostream>
using namespace std;
int n, k, x, cnt = 1, Sum[100], A[100][100];
int main() {
    cin >> n >> k >> x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
            if (i & 1) Sum[j] += A[i][j];//直接先把偶数行各列值分别加上(下标从0开始) 
        }
    }
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < cnt; j++) Sum[j] += x;
        for (int j = cnt; j < n; j++) Sum[j] += A[i][j-cnt];
        cnt = cnt % k + 1;//先模后加1得[1, mod]的数，先加1后模得[0, mod-1]的数 
    }
    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << Sum[i];
    }
    return 0;
}
