#include <iostream>
using namespace std;
int main() {
    string s, s1, s2, ans;
    int carry = 0, flag = 0;
    cin >> s >> s1 >> s2;
    ans = s;
    string ss1(s.length() - s1.length(), '0');//����һ���ַ�����(���ȣ������ַ���ֵΪ'0') 
    s1 = ss1 + s1;//��2���������ȴ��ڵ��ڽ��Ʊ�
    string ss2(s.length() - s2.length(), '0');
    s2 = ss2 + s2;
    for(int i = s.length() - 1; i >= 0; i--) {
        int mod = s[i] == '0' ? 10 : (s[i] - '0');
        ans[i] = (s1[i] - '0' + s2[i] - '0' + carry) % mod + '0';
        carry = (s1[i] - '0' + s2[i] - '0' + carry) / mod;
    }
    if (carry != 0) ans = '1' + ans;//ע����������ÿһλ�ǲ�ͬ���Ƶģ�ÿλ���������ܳ���������ʾ��Χ������ÿλ�Ľ�λ���Ϊ1 
    for(int i = 0; i < ans.length(); i++) {//ע�Ȿ���������ǳ���9*10^18(19λ��ʮ����)��longlongҲ�޷���ʾ��ֻ���ַ������ 
        if (ans[i] != '0' || flag == 1) {//������һ����0���֣���flagΪ1������λ��������� 
            flag = 1;
            cout << ans[i];
        }
    }
    if (flag == 0) cout << 0;
    return 0;
}
