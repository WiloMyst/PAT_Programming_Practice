#include <iostream>
using namespace std;
int main() {
    int n, t, a[10000] = {0};
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        a[abs(t-i)]++;
    }
    for (int i = 9999; i >= 0; i--)
        if (a[i] >= 2) cout << i << " " << a[i] << endl;
    return 0;
}
    //µ¹×ÅÊä³ömapÄÚÈÝ£º
    //for (auto it = a.rbegin(); it != a.rend(); it++)
    //    if (it->second >= 2) cout << it->first << " " << it->second << endl;
