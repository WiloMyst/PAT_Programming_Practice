#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;     //�ֵ�������ע��㣺 
char name[40010][5];     //��������ʱ�����char[]����ַ��� 
vector<int> course[2510];//�����string����������ʱ���׳�ʱ�����ƣ���ÿ��string��Ҫ������length��char*�����ַ���������������ʱ���׳����ڴ����� 
bool cmp1(int a, int b) {//ֻ��int�����±꣬���±갴�����Ӧ�ַ����ֵ������򣬽���Ч�����ƶ�����
    return strcmp(name[a], name[b]) < 0;//����д<0����Ҫд!=-1 
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

//For the sake of Ϊ��...��� 
//alphabetical order / dictionary order �ֵ���(��ĸ��) 
