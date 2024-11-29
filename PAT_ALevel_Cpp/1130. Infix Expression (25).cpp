#include <iostream>
using namespace std;
struct node {
    string data;
    int l, r;
}a[100];//静态存储二叉树
string dfs(int root) {//写法值得学习 
    if(a[root].l == -1 && a[root].r == -1) return a[root].data;
    if(a[root].l == -1 && a[root].r != -1) return "(" +  a[root].data + dfs(a[root].r) + ")";
    if(a[root].l != -1 && a[root].r != -1) return "(" +  dfs(a[root].l) + a[root].data + dfs(a[root].r) + ")";
}
int main() {
    int have[100] = {0}, n, root = 1;
    cin >> n;
    for(int i  = 1; i <= n; i++) {
        cin >> a[i].data >> a[i].l >> a[i].r;//静态存储二叉树的构建 
        if(a[i].l != -1) have[a[i].l] = 1;//存在的非根结点全做标记 
        if(a[i].r != -1) have[a[i].r] = 1;
    }
    while(have[root] == 1) root++;//1~n中找到根结点 
    string ans = dfs(root);
    if(ans[0] == '(') ans = ans.substr(1, ans.size()-2);//除了单结点的情况，其它都要去除最外层() 
    cout << ans;
    return 0;
}

//syntax tree 语法树
//prefix expression 前缀表达式 
//infix expression 中缀表达式 
//postfix expression 后缀表达式
//parentheses 括号/插入语
//precedence 优先权 
