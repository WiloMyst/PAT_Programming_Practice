#include <iostream>//̰�ģ��ֲ����ŵ�ȫ������ 
#include <string>
#include <algorithm>
using namespace std;
bool cmp0(string a, string b) {//�ֵ��ѧϰ��(�漰��ĳ������������뵽sort��cmp) 
    return a + b < b + a;
}
string str[10010];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        cin >> str[i];
    sort(str, str + n, cmp0);
    string s;
    for(int i = 0; i < n; i++)
        s += str[i];
    while(s.length() > 1 && s[0] == '0')//ǰ��0���ֻ��ɾ��������2λ 
        s.erase(s.begin());//ɾͷ0 
    cout << s;
    return 0;
}

//with respect to ���� 
