#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	int n, m, optnum, truenum, temp, maxcnt = 0;
	int hash[] = {1, 2, 4, 8, 16};//λɢ�У��ö�������5λ��ÿ1λ����һ��ѡ��ѡûѡ������11110BΪѡabcd
	int opt[1010][110] = {0};//�洢ÿ��ѧ��ÿ�����ѡ�����(ѡ����)
	char c;
	scanf("%d %d", &n, &m);
	vector<int> fullscore(m), trueopt(m);
	vector<vector<int>> cnt(m, vector<int>(5));//�洢ÿ����ÿ��ѡ��Ĵ������
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &fullscore[i], &optnum, &truenum);
		for (int j = 0; j < truenum; j++) {
			scanf(" %c", &c);
			trueopt[i] += hash[c-'a'];
		}
	}
	for (int i = 0; i < n; i++) {
		double grade = 0;
		for (int j = 0; j < m; j++) {
			getchar();
			scanf("(%d", &temp);
			for (int k = 0; k < temp; k++) {//��¼ѡ����
				scanf(" %c)", &c);//��ȡ���������")"�����ڣ�������
				opt[i][j] += hash[c-'a'];
			}
			int el = opt[i][j] ^ trueopt[j];//ѡ�����Ƿ�һ��
			if (el) {//ѡ���ֲ�һ�±�����������
				if ((opt[i][j] | trueopt[j]) == trueopt[j]) {//����λ���������ȷѡ���֣�����ֻ��©ѡ
					grade += fullscore[j] * 1.0 / 2;
				}
				for (int k = 0; k < 5; k++)
					if (el & hash[k]) cnt[j][k]++;
			} else {
				grade += fullscore[j];
			}
		}
		printf("%.1f\n", grade);
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < 5; j++)
			maxcnt = maxcnt > cnt[i][j] ? maxcnt : cnt[i][j];
	if (maxcnt == 0) {
		printf("Too simple\n");
	} else {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < cnt[i].size(); j++) {
				if (maxcnt == cnt[i][j])
					printf("%d %d-%c\n", maxcnt, i+1, 'a'+j);
			}
		}
	}
	return 0;
}
