#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    for(int i = 0; i < k; i++) {
        bool flag = false;
        stack<int> s;
        vector<int> v(n + 1);
        for(int j = 1; j <= n; j++)
            scanf("%d", &v[j]);
        int current = 1;
        for(int j = 1; j <= n; j++) {//˳����ջ 
            s.push(j);
            if(s.size() > m) break;//��ջ���Ϸ� 
            while(!s.empty() && s.top() == v[current]) {//ֻҪջ���ͳ�վ���е�ǰԪ��һ�£����ϳ�ջ 
                s.pop();
                current++;
            }
        }
        if(current == n + 1) flag = true;//������кϷ���ָ����ߵ����(����ģ��������������ָ���Ƿ��ߵ������Ϊ�ж�����) 
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
