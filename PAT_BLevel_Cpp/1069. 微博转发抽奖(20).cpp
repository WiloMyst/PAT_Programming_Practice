#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
    int m, n, s;
    scanf("%d%d%d", &m, &n, &s);
    vector<string> a(m+1);
    map<string, int> mapp;
    bool flag = false;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    while (s <= m) {
        if (mapp[a[s]] == 1) s++;
        else {
            mapp[a[s]] = 1;
            cout << a[s] << endl;
            flag = true;
            s = s + n;
        }
    }
    if (flag == false) cout << "Keep going...\n";
    return 0;
}
