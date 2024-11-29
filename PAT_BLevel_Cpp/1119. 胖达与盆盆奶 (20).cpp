#include <iostream>
using namespace std;
int n, ans, A[10005], L[10005], R[10005];
int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 1; i < n; i++) {
        int j = i;
        while(j + 1 <= n && A[j] >= A[j + 1]) {
            if (A[j] > A[j + 1]) ++L[i];
            ++j;
        }
    }
    for (int i = n; i > 1; i--) {
        int j = i;
        while(j - 1 >= 1 && A[j] >= A[j - 1]) {
            if (A[j] > A[j - 1]) ++R[i];
            --j;
        }
    }
    for (int i = 1; i <= n; i++) ans += max(L[i], R[i]) * 100 + 200;
    cout << ans;
    return 0;
}
//我的代码： 
//#include <iostream>
//using namespace std;
//int W[10005], Milk[10005];
//int main() {
//	int n, sum = 0, flag = 1;
//	cin >> n;
//	for(int i = 0; i < n; i++) {
//		cin >> W[i];
//		Milk[i] = 200;
//	}
//	while(flag) {
//		flag = 0;
//		for(int i = 0; i < n-1; i++) {
//			if(W[i] > W[i+1])
//				if(Milk[i] <= Milk[i+1]) {
//					Milk[i] = Milk[i+1] + 100;
//					flag = 1;
//				}
//			if(W[i] < W[i+1])
//				if(Milk[i] >= Milk[i+1]) {
//					Milk[i+1] = Milk[i] + 100;
//					flag = 1;
//				}
//			if(W[i] == W[i+1])//千万别写错==，很难发现错误 
//				if(Milk[i] > Milk[i+1]) {
//					Milk[i+1] = Milk[i];
//					flag = 1;
//				} else if(Milk[i] < Milk[i+1]) {
//					Milk[i] = Milk[i+1];
//					flag = 1;
//				}
//		}
//	}
//	for(int i = 0; i < n; i++) sum += Milk[i];
//	cout << sum;
//	return 0;
//}
