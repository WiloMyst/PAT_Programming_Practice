#include <iostream>
#include <map>
using namespace std;
int main(){
	int n, num;
	map<int, int> m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if(num & 1) m[num]++;
    }
    for (auto it : m) {
    	if (it.second & 1) {
    		cout << it.first;
    		break;
		}
	}
    return 0;
}
