#include <iostream>
using namespace std;
int main() {
    string s;
    cin >> s;
    int i = 0;              //��ѧ������ת��ͨ���������裺
    while (s[i] != 'E') i++;//һ�ֵ�����ָ��
    string t = s.substr(1, i-1);
    int n = stoi(s.substr(i+1));		//stringתintʱ+-��Ҳ�ᱻת�� 
    if (s[0] == '-') cout << "-";//���Ÿ���
    if (n < 0) {//����ָ��<0����>=0��������
        cout << "0.";
        for (int j = 0; j < abs(n) - 1; j++) cout << '0';
        for (int j = 0; j < t.length(); j++)
            if (t[j] != '.') cout << t[j];
    } else {
        cout << t[0];
        int cnt, j;
        for (j = 2, cnt = 0; j < t.length() && cnt < n; j++, cnt++) cout << t[j];
        if (j == t.length()) {
            for (int k = 0; k < n - cnt; k++) cout << '0';
        } else {
            cout << '.';
            for (int k = j; k < t.length(); k++) cout << t[k];
        }
    }
    return 0;
}
