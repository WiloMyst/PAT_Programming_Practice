#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;     //字典序排序注意点： 
char name[40010][5];     //数据量大时最好用char[]存放字符串 
vector<int> course[2510];//如果用string，数据量大时容易超时间限制，对每个string都要存它的length、char*、与字符串自身，数据量大时容易超过内存限制 
bool cmp1(int a, int b) {//只存int类型下标，对下标按照其对应字符串字典序排序，将有效减少移动次数
    return strcmp(name[a], name[b]) < 0;//必须写<0，不要写!=-1 
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        int cnt, temp;
        scanf("%s %d", name[i], &cnt);
        for(int j = 0; j < cnt; j++) {
            scanf("%d", &temp);
            course[temp].push_back(i);
        }
    }
    for(int i = 1; i <= k; i++) {
        printf("%d %d\n", i, course[i].size());
        sort(course[i].begin(), course[i].end(), cmp1);
        for(int j = 0; j < course[i].size(); j++)
            printf("%s\n", name[course[i][j]]);
    }
    return 0;
}

//For the sake of 为了...起见 
//alphabetical order / dictionary order 字典序(字母序) 
