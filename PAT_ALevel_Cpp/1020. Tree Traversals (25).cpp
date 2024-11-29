#include <cstdio>
#include <vector>
#include <map>
using namespace std;
vector<int> post, in;
map<int, int> level;//���ڲ������˳��ǡ���ǰ��ն�����������ȫ����ţ���ÿ��������ȫ����Ŷ�����������������еõ�(���������к󣬵ݹ�ʱһ���ܵõ��¸�������ȫ�����)
void pre(int root, int start, int end, int index) {//����ֱ�������С���������ʵ��ģ������������̣����ý���(�������̱���һ�㶼�������) (���ϵ��ҵ�ǰ�����+"��Ƭ") 
    if(start > end) return ;
    int i = start;
    while(i < end && in[i] != post[root]) i++;
    level[index] = post[root];//������ȫ����ţ�map�Զ������ֵ��������������Ϊ�������� 
    pre(root - 1 - end + i, start, i - 1, 2 * index + 1);//��������ݹ�ʱ����ֱ�ӵõ��¸�������ȫ����� 
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

//level order traversal sequence ����������� 
