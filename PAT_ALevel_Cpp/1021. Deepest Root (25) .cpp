#include <iostream>//����Ҫ������ܹ�������������и���� 
#include <vector>  //����������һ�ⷨ������2��DFS����һ����ȡ����DFS��������������Ҷ��㣻�ڶ�����ȡһ����Ҷ���DFS��������������Ҷ��㡣������������Ҷ���ȡ������Ϊ���� 
#include <set>     //��ʵ���൱�ڣ���һ��DFS�õ������·����һ�˶��㣬�ڶ���DFS�õ���һ�˶��㡣 
#include <algorithm>
using namespace std;
int n, maxheight = 0;
vector<vector<int>> v;//�ڽӱ� (�ڽӾ���ᳬʱ) 
bool visit[10010];
set<int> s;//������Ҷ���
vector<int> temp;//DFS���ݴ�����Ҷ��� 
void dfs(int node, int height) {
    if(height > maxheight) {
        temp.clear();
        temp.push_back(node);
        maxheight = height;
    } else if(height == maxheight){
        temp.push_back(node);
    }
    visit[node] = true;
    for(int i = 0; i < v[node].size(); i++) {
        if(visit[v[node][i]] == false)
            dfs(v[node][i], height + 1);
    }
}
int main() {
    scanf("%d", &n);
    v.resize(n + 1);
    int a, b, cnt = 0, s1 = 0;
    for(int i = 0; i < n - 1; i++) {//����ֻ��n-1���ߣ����ֻ�������������ͨͼ��(��Ȼn-1���߲���ʹ��ͨͼ���ɻ�) 
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) {//��һ��DFS��ͬʱ��¼��ͨ������ 
        if(visit[i] == false) {
            dfs(i, 1);
            if(i == 1) {//�ڶ�����ͨ����û��Ҫ�� 
                if (temp.size() != 0) s1 = temp[0];
                for(int j = 0; j < temp.size(); j++)
                    s.insert(temp[j]);
            }
            cnt++;
        }
    }
    if(cnt >= 2) {
        printf("Error: %d components", cnt);
    } else {//�ڶ���DFS 
        temp.clear();
        maxheight = 0;
        fill(visit, visit + 10010, false);
        dfs(s1, 1);
        for(int i = 0; i < temp.size(); i++)
            s.insert(temp[i]);//�󲢼�����ֱ����set<>���� 
        for(auto it = s.begin(); it != s.end(); it++)
            printf("%d\n", *it);
    }
    return 0;
}

//acyclic ��ѭ����  cyclic ѭ����
//connected component ��ͨ���� 
