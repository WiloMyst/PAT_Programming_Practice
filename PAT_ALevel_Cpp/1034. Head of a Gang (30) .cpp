#include <iostream>//�ܵ���˵���ж�һ��ͼ����ͨ�����ĸ�������ͼ�ı��������������ȱ���
#include <map>     //���һ���Ż���������2�˲���ͨ����Ȩֵ����k�����Ż����������Ȩֵ�����ֵΪͷĿ��������������������Ż��ͷĿ���������Ż���������� 
using namespace std;
map<string, int> stringToInt;//����ת���� 
map<int, string> intToString;//����ת���� 
map<string, int> ans;//map��𰸣��Զ����ֵ������� 
int idNumber = 1, k;
int stoifunc(string s) {
    if(stringToInt[s] == 0) {
        stringToInt[s] = idNumber;
        intToString[idNumber] = s;
        return idNumber++;
    } else {
        return stringToInt[s];
    }
}
int G[2010][2010], weight[2010];//��Ȩ�͵�Ȩ 
bool vis[2010];//visit���� 
void dfs(int u, int &head, int &numMember, int &totalweight) {//���ò���������ֵ 
    vis[u] = true;
    numMember++;
    if(weight[u] > weight[head])
        head = u;
    for(int v = 1; v < idNumber; v++) {
        if(G[u][v] > 0) {//ע�⣬��������������Ǳߴ���&&��δ���ʣ�����ֻ��ͳ��DFS���ϵı�Ȩ����������ͳ����ͨ�������ܱ�Ȩ 
            totalweight += G[u][v];
            G[u][v] = G[v][u] = 0;//ͳ�ƺ��ɾ�ñߣ���ֹ��Ȩ���ظ�ͳ�� 
            if(vis[v] == false)
                dfs(v, head, numMember, totalweight);
        }
    }
}
void dfsTrave() {
    for(int i = 1; i < idNumber; i++) {
        if(vis[i] == false) {
            int head = i, numMember = 0, totalweight = 0;
            dfs(i, head, numMember, totalweight);
            if(numMember > 2 && totalweight > k)
                ans[intToString[head]] = numMember;
        }
    }
}
int main() {
    int n, w;
    cin >> n >> k;
    string s1, s2;
    for(int i = 0; i < n; i++) {
        cin >> s1 >> s2 >> w;
        int id1 = stoifunc(s1);
        int id2 = stoifunc(s2);
        weight[id1] += w;
        weight[id2] += w;
        G[id1][id2] += w;
        G[id2][id1] += w;
    }
    dfsTrave();
    cout << ans.size() << endl;
    for(auto it = ans.begin(); it != ans.end(); it++)
        cout << it->first << " " << it->second << endl;
    return 0;
}

//threshold ��ֵ���ż� 
