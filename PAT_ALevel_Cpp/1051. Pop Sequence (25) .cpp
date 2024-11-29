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
        for(int j = 1; j <= n; j++) {//顺序入栈 
            s.push(j);
            if(s.size() > m) break;//爆栈不合法 
            while(!s.empty() && s.top() == v[current]) {//只要栈顶和出站序列当前元素一致，不断出栈 
                s.pop();
                current++;
            }
        }
        if(current == n + 1) flag = true;//如果序列合法，指针会走到最后(过程模拟问题往往可用指针是否走到最后作为判断条件) 
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
