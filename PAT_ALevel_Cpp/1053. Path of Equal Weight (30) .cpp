#include <iostream>//greater<>��less<>���������� 
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 110;
struct node {
    int weight;
    vector<int> child;
} Node[maxn];
int n, m, s;
vector<int> path; //·��
vector<vector<int> > ans; //�������·����(">"��ӿո��ֹC++11��׼ǰ�ı�������Ϊ��λ����)
void DFS(int index, int sum) {
    if (sum > s) return;
    if (sum == s) {
        if (Node[index].child.size() != 0) return; //��δ��Ҷ�ӽ��
        ans.push_back(path);
        return;
    }
    for (int i = 0; i < Node[index].child.size(); i++) {
        int child = Node[index].child[i];
        path.push_back(Node[child].weight);
        DFS(child, sum + Node[child].weight);
        path.pop_back();//ɾ��vectorĩβԪ�� 
    }
}
int main() {
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 0; i < n; i++)
        scanf("%d", &Node[i].weight);
    int id, k, child;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &id, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &child);
            Node[id].child.push_back(child);
        }
    }
    path.push_back(Node[0].weight);
    DFS(0, Node[0].weight);
    //������·�����ֵ���Ӵ�С����greater<vector<int> >() 
    sort(ans.begin(), ans.end(), greater<vector<int> >());//ע�⣬��һ���뷨������׶ζ�ÿ�����ĺ��Ӱ�Ȩ�شӴ�С�����Ǵ�ġ���Ϊ����ֵ��ͬ���������ӣ����ǵĺ���֮�䲻һ���ֵ併�򣬴Ӷ�����ǰ�߲�����·���ֵ������С�ں��ߡ� 
    for (int i = 0; i < ans.size(); i++) {
        printf("%d", ans[i][0]);
        for (int j = 1; j < ans[i].size(); j++)
            printf(" %d", ans[i][j]);
        printf("\n");
    }
    return 0;
}
