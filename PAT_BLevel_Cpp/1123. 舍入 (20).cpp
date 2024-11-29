#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
	int N, D, ins;
	string num, pre, post, ans;
	cin >> N >> D;
	for (int i = 0; i < N; i++) {//处理内容统一格式越早做越好
		cin >> ins >> num;
		int c = 0, j;//c为进位
		if(num.find('.') == string::npos) num += ".0";
		int dot = num.find('.');//查找'.'的位置
		pre = num.substr(0, dot);
		post = num.substr(dot + 1);
		if(post.length() <= D) {//令小数点后有效位数达到D
			string str(D - post.length(), '0');
			post += str;
		}
		if(ins == 1) {//3种指令的区别主要在于计算初始进位c 
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
		}//再将进位完成后的数串计算出来
		for(j = D - 1; j >= 0 && c == 1; j--) {//小数部分逐位进位
			post[j] += 1;
			c = 0;
			if(post[j] > '9') {
				post[j] -= 10;
				c = 1;
			}
		}
		for(j = dot - 1; j >= 0 && c == 1 && isdigit(pre[j]); j--) {//整数部分逐位进位
			pre[j] += 1;
			c = 0;
			if(pre[j] > '9') {
				pre[j] -= 10;
				c = 1;
			}
		}
		if(c == 1) //若还有进位，就在符号和最高位之间插入一个"1"
			pre.insert(++j, "1");//insert必须插入字符串型
		post = post.substr(0, D);//截断多余尾数
		ans = pre + '.' + post;//组成数串 
		if(ans[0] == '-') {//负零处理
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
