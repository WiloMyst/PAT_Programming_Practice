#include <iostream>
#include <map>
using namespace std;
int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    map<int, int> arr;
    int half = m * n / 2;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int temp;
            scanf("%d", &temp);
            arr[temp]++;
            if(arr[temp] > half) {
                printf("%d", temp);
                return 0;
            }
        }
    }
    return 0;
}

//A strictly dominant color 严格意义上的主色
//resolution M by N  分辨率 M乘N 
