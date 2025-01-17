#include <iostream>
#include <cmath>
using namespace std;
int m, x, y;
void print(double t) {
    if (m == t) printf(" Ping");//int可以和double直接比较 
    else if (m < t) printf(" Cong");
    else printf(" Gai");
}
int main() {
    scanf("%d %d %d", &m, &x, &y);
    for (int i = 99; i >= 10; i--) {
        int j = i % 10 * 10 + i / 10;
        double k = abs(j - i) * 1.0 / x;
        if (j == k * y) {//本题因为符合条件的k必为整数，计算是准确的，可直接用等号 
            cout << i;
            print(i); print(j); print(k);
            return 0;
        }
    }
    cout << "No Solution";
    return 0;
}
