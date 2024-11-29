#include <iostream>
#include <string>
using namespace std;
int K, N;
string s;
int main(){
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> s;
        int len = s.length();
        int num = 0, j;
        for (j = 0; j < len; j++) {
        	num = num * 10 + s[j] - '0';
        	if(num % (j + 1) != 0) break;
        }
        cout << (j == len ? "Yes\n" : "No\n");
    }
    return 0;
}
