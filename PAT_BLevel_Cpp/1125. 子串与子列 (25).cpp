#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	int i, k;
	int minlen = 10005, len;
	string s, p, temp;
	cin >> s >> p;
	vector<string> v;
	vector<int> id(p.length(), 0);//��¼p����ĸλ��
	while(id[0] < s.length()) {
		for(i = 0; i < p.length(); i++) {
			while(id[i] < s.length() && s[id[i]] != p[i]) id[i]++;//id[i]��p�и��ַ���λָ�� 
			if(i+1 < p.length()) id[i+1] = id[i] + 1;
		}
		int flag = 0;//��id[i]�Ƿ�Ϸ� 
		for(k = 0; k < p.length(); k++) 
			if(id[k] >= s.length()) {
				flag = 1;
				break;
			}
		if(!flag) {
			temp = s.substr(id[0], id[p.length()-1] - id[0] + 1);
			len = temp.length();
			if(len < minlen) {
				minlen = len;
				v.push_back(temp);
			}
		}
		id[0]++;
	}
	cout << v[v.size()-1];
	return 0;
}
