#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
	int N, D, ins;
	string num, pre, post, ans;
	cin >> N >> D;
	for (int i = 0; i < N; i++) {//��������ͳһ��ʽԽ����Խ��
		cin >> ins >> num;
		int c = 0, j;//cΪ��λ
		if(num.find('.') == string::npos) num += ".0";
		int dot = num.find('.');//����'.'��λ��
		pre = num.substr(0, dot);
		post = num.substr(dot + 1);
		if(post.length() <= D) {//��С�������Чλ���ﵽD
			string str(D - post.length(), '0');
			post += str;
		}
		if(ins == 1) {//3��ָ���������Ҫ���ڼ����ʼ��λc 
			if(post[D] >= '5') c = 1;
		} else if(ins == 3) {
			if(post[D] > '5') c = 1;
			else if(post[D] == '5') {
				int flag = 0;
				for(int k = D + 1; k < post.length(); k++) {
					if(post[k] != '0') {
						flag = 1;
						break;
					}
				}
				if(flag) c = 1;
				else if((post[D-1] - '0') & 1) c = 1;
				else c = 0;
			}
		}//�ٽ���λ��ɺ�������������
		for(j = D - 1; j >= 0 && c == 1; j--) {//С��������λ��λ
			post[j] += 1;
			c = 0;
			if(post[j] > '9') {
				post[j] -= 10;
				c = 1;
			}
		}
		for(j = dot - 1; j >= 0 && c == 1 && isdigit(pre[j]); j--) {//����������λ��λ
			pre[j] += 1;
			c = 0;
			if(pre[j] > '9') {
				pre[j] -= 10;
				c = 1;
			}
		}
		if(c == 1) //�����н�λ�����ڷ��ź����λ֮�����һ��"1"
			pre.insert(++j, "1");//insert��������ַ�����
		post = post.substr(0, D);//�ض϶���β��
		ans = pre + '.' + post;//������� 
		if(ans[0] == '-') {//���㴦��
			int iszero = 1;
			for(int k = 1; k < ans.length(); k++)
				if(ans[k] != '0' && ans[k] != '.') {
					iszero = 0;
					break;
				}
			if(iszero) ans.erase(ans.begin());
		}
		cout << ans << endl;
	}
	return 0;
}
