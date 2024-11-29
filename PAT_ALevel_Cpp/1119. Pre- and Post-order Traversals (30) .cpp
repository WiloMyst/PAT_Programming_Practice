#include <iostream>
#include <vector>
using namespace std;
vector<int> in, pre, post;
bool unique = true;
void getIn(int preLeft, int preRight, int postLeft, int postRight) {
	if(preLeft == preRight) {
		in.push_back(pre[preLeft]);
		return;
	}
	if (pre[preLeft] == post[postRight]) {
		int i = preLeft + 1;
		while (i <= preRight && pre[i] != post[postRight-1]) i++;
		if (i - preLeft > 1)
			getIn(preLeft + 1, i - 1, postLeft, postLeft + (i - preLeft - 1) - 1);
		else//每次取后序的根结点的前面一个结点，在前序中找他的位置。如果发现他的左侧还有其他结点，就可以确定该结点一定是根的右孩子；如果没有，则他既可能是左孩子也可能是右孩子(导致答案不唯一)，但由样例知应作为右孩子输出答案。 
			unique = false;
		in.push_back(post[postRight]);//中序递归生成中序序列 
		getIn(i, preRight, postLeft + (i - preLeft - 1), postRight - 1);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	pre.resize(n), post.resize(n);
	for (int i = 0; i < n; i++) 
		scanf("%d", &pre[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &post[i]);
	getIn(0, n-1, 0, n-1);
	printf("%s\n%d", unique == true ? "Yes" : "No", in[0]);
	for (int i = 1; i < in.size(); i++)
		printf(" %d", in[i]);
	printf("\n");
	return 0;
}
