#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
struct node {
    int n, num;
    friend bool operator < (node &a, node &b) {//友元，重定义< 
        if (a.n != b.n) return a.n < b.n;
        return a.num < b.num;
    }
}T;
int N, K, m, temp, sum, sum2, I, II;
vector<node> A;
int is_prime(int x) {
    if (x <= 2) return 0;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) return 0; 
    }
    return 1;
}
int main() {
    cin >> N;
    for (int i = 1 ; i <= N; i++) {
        A.clear();
        cout << "Case " << i << '\n';
        cin >> K >> m;
        if (K * 9 < m) cout << "No Solution\n";
        else {
            temp = pow(10, K - 2);//试运行后发现结果后四位一定是9，本题需砍掉几位来减少运行时间 
            for (int i = temp / 10; i < temp; i++) {
                sum = 18, sum2 = 0, I = i, II = i + 1;
                while (I) {
                    sum += I % 10;
                    I /= 10;
                    if (sum > m) break;
                }
                while (II) {
                    sum2 += II % 10;
                    II /= 10;
                }
                if (sum == m && is_prime(__gcd(m, sum2))) {//__gcd求最大公约数，在头文件<algorithm>中，int、longlong都可以用 
                    T.n = sum2, T.num = i;
                    A.push_back(T);
                }
            }
            sort(A.begin(), A.end());
            if (A.empty()) cout << "No Solution\n";
            for (auto &it : A) {//C++11新增遍历方式，加&表示引用，不加表示值拷贝 
                cout << it.n << ' ' << it.num << "99\n";
            }
        }        
    }
    return 0;
}
