#include <iostream>
#include <map>
using namespace std;
int main() {
    int n, m, temp;
    scanf("%d", &n);
    map<int, int> b;
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        b[temp]++;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &temp);
        if (i != 0) printf(" ");
        printf("%d", b[temp]);
    }
    return 0;
}
