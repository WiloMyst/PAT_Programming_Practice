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
    int minans = sum[n];//����֧���Ľ��
    for(int i = 1; i <= n; i++) {//����"�����в��ҵ�һ��ʹxx������λ��"�����⣬�ɿ�����STL�Ķ��ֲ���lower_bound()��upper_bound() 
        int j, tempsum;//���ֲ��ң��ҵ�sum�е�һ�����ڵ���sum[i-1]+m��sum[j] (����һ��sum[j]-sum[i-1]>=m��λ��) 
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

//ע�⣬lower_bound()��upper_bound()Ĭ���������������ҵ�һ�� >= val���һ�� > val�����ص���ָ�������� 
//��Ҫ���������ҵ�һ�� <= val���һ�� < val����Ҫ�Ӳ������磺
//lower_bound(a, a+n, val, greater<int>() ) 
//lower_bound(a, a+n, val, cmp )�����У� 
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
