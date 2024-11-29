#include <cstdio>
using namespace std;
int main() {
    int cnt;
    scanf("%d", &cnt);
    int start[55], end[55], scan[55];
    for(int i = 1; i < 55; i++) {
        scanf("%d", &scan[i]);
        end[i] = i;
    }
    for(int i = 0; i < cnt; i++) {
        for(int j = 1; j < 55; j++)
            start[j] = end[j];
        for(int k = 1; k < 55; k++)
            end[scan[k]] = start[k];
    }
    char c[6] = {"SHCDJ"};//打表，巧妙输出结果 
    for(int i = 1; i < 55; i++) {
        end[i] = end[i] - 1;//注意，只有从0开始计数，才能由除法或求模得到打表的正确位置 
        printf("%c%d", c[end[i]/13], end[i]%13+1);
        if(i != 54) printf(" ");
    }
    return 0;
}

//playing cards 扑克牌
//a deck of 一副
//inside job 内部工作，监守自盗
//casino 赌场
//stand for 代表 
