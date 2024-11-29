#include <cstdio>
#include <vector>
#include <map>
using namespace std;
vector<int> post, in;
map<int, int> level;//由于层序遍历顺序恰好是按照二叉树结点的完全树编号，而每个结点的完全树编号都能在先序遍历过程中得到(不论是先中后，递归时一定能得到下个结点的完全树编号)
void pre(int root, int start, int end, int index) {//可以直接利用中、后序序列实现模拟先序遍历过程，不用建树(建树过程本身一般都是先序的) (不断地找当前根结点+"切片") 
    if(start > end) return ;
    int i = start;
    while(i < end && in[i] != post[root]) i++;
    level[index] = post[root];//借助完全树编号，map自动将结点值由先序序列重排为层序序列 
    pre(root - 1 - end + i, start, i - 1, 2 * index + 1);//先序遍历递归时可以直接得到下个结点的完全树编号 
    pre(root - 1, i + 1, end, 2 * index + 2);
}
int main() {
    int n;
    scanf("%d", &n);
    post.resize(n);
    in.resize(n);
    for(int i = 0; i < n; i++) scanf("%d", &post[i]);
    for(int i = 0; i < n; i++) scanf("%d", &in[i]);
    pre(n-1, 0, n-1, 0);
    auto it = level.begin();
    printf("%d", it->second);
    while(++it != level.end()) printf(" %d", it->second);
    return 0;
}

//level order traversal sequence 层序遍历序列 
