#include <iostream>
#include <queue>
using namespace std;
struct node {
    int weight, rank;
}mouse[1010];//下标为参赛者编号 
int main() {
    int np, ng, order;//order为当前参赛者编号 
    scanf("%d%d", &np, &ng);
    for(int i = 0; i < np; i++)
        scanf("%d", &mouse[i].weight);
    queue<int> q;
    for(int i = 0; i < np; i++) {
        scanf("%d", &order);
        q.push(order);
    }
    int temp = np, group;//temp为当轮比赛的老鼠总数 
    while(q.size() != 1) {
        group = temp / ng;
        if(temp % ng != 0) group++;
        for(int i = 0; i < group; i++) {//用group和ng体现queue中元素处理时的差异性 
            int maxm = q.front();//最胖老鼠 
            for(int j = 0; j < ng; j++) {
                if(i * ng + j >= temp) break;//限制最后一组的循环次数 
                int front = q.front();
                if(mouse[front].weight > mouse[maxm].weight)
                    maxm = front;
                mouse[front].rank = group + 1;//注意当轮失败者排名恰为当轮group+1 
                q.pop();
            }
            q.push(maxm);
        }
        temp = group;
    }
    mouse[q.front()].rank = 1;
    for(int i = 0; i < np; i++) {
        if(i != 0) printf(" ");
        printf("%d", mouse[i].rank);
    }
    return 0;
}

//a permutation of 0...N  0到N的置换 
//initial playing order  初始比赛顺序 
