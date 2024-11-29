#include <iostream>
#include <vector>
using namespace std;
int main() {
	int N, ans, dis, mindis = 0x7fffffff, i;
	cin >> N;
	int v[10005] = {0};
	v[0] = 0; v[1] = 1; v[2] = 1;
	if(N == 1) ans = 1;
	else if(N == 2) ans = 2;
	else if(N > 2){
		dis = abs(N - 1);
		for(i = 3; dis < mindis; i++){
			mindis = dis;
			v[i] = v[i-1] + v[i-2];
			dis = abs(N - v[i]);
		}
		ans = v[i-2];
	}
	cout << ans;
	return 0;
}
