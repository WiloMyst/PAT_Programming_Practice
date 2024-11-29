#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> sum, resultArr;
int n, m;
int main() {
    scanf("%d%d", &n, &m);
    sum.resize(n+1);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &sum[i]);
        sum[i] += sum[i-1];
    }
    int minans = sum[n];//至少支付的金额
    for(int i = 1; i <= n; i++) {//对于"序列中查找第一个使xx成立的位置"的问题，可考虑用STL的二分查找lower_bound()或upper_bound() 
        int j, tempsum;//二分查找，找到sum中第一个大于等于sum[i-1]+m的sum[j] (即第一个sum[j]-sum[i-1]>=m的位置) 
        j = lower_bound(sum.begin()+1, sum.end(), sum[i-1] + m) - sum.begin();
        tempsum = sum[j] - sum[i-1];
        if(tempsum > minans) continue;
        if(tempsum >= m) {
            if(tempsum < minans) {
                resultArr.clear();
                minans = tempsum;
            }
            resultArr.push_back(i);
            resultArr.push_back(j);
        }
    }
    for(int i = 0; i < resultArr.size(); i += 2)
        printf("%d-%d\n", resultArr[i], resultArr[i+1]);
    return 0;
}

//注意，lower_bound()或upper_bound()默认用于升序序列找第一个 >= val或第一个 > val，返回的是指针或迭代器 
//若要降序序列找第一个 <= val或第一个 < val，则要加参数，如：
//lower_bound(a, a+n, val, greater<int>() ) 
//lower_bound(a, a+n, val, cmp )，其中： 
//bool cmp(const int &a, const int &b) { 
//    return a > b;
//}


//#include <iostream>
//#include <vector>
//using namespace std;
//vector<int> sum, resultArr;
//int n, m;
//void Func(int i, int &j, int &tempsum) {
//    int left = i, right = n;
//    while(left < right) {
//        int mid = (left + right) / 2;
//        if(sum[mid] - sum[i-1] >= m)
//            right = mid;
//        else
//            left = mid + 1;
//    }
//    j = right;
//    tempsum = sum[j] - sum[i-1];
//}
//int main() {
//    scanf("%d%d", &n, &m);
//    sum.resize(n+1);
//    for(int i = 1; i <= n; i++) {
//        scanf("%d", &sum[i]);
//        sum[i] += sum[i-1];
//    }
//    int minans = sum[n];
//    for(int i = 1; i <= n; i++) {
//        int j, tempsum;
//        Func(i, j, tempsum);
//        if(tempsum > minans) continue;
//        if(tempsum >= m) {
//            if(tempsum < minans) {
//                resultArr.clear();
//                minans = tempsum;
//            }
//            resultArr.push_back(i);
//            resultArr.push_back(j);
//        }
//    }
//    for(int i = 0; i < resultArr.size(); i += 2)
//        printf("%d-%d\n", resultArr[i], resultArr[i+1]);
//    return 0;
//}
