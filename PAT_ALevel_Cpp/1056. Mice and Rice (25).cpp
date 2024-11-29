#include <iostream>
#include <queue>
using namespace std;
struct node {
    int weight, rank;
}mouse[1010];//�±�Ϊ�����߱�� 
int main() {
    int np, ng, order;//orderΪ��ǰ�����߱�� 
    scanf("%d%d", &np, &ng);
    for(int i = 0; i < np; i++)
        scanf("%d", &mouse[i].weight);
    queue<int> q;
    for(int i = 0; i < np; i++) {
        scanf("%d", &order);
        q.push(order);
    }
    int temp = np, group;//tempΪ���ֱ������������� 
    while(q.size() != 1) {
        group = temp / ng;
        if(temp % ng != 0) group++;
        for(int i = 0; i < group; i++) {//��group��ng����queue��Ԫ�ش���ʱ�Ĳ����� 
            int maxm = q.front();//�������� 
            for(int j = 0; j < ng; j++) {
                if(i * ng + j >= temp) break;//�������һ���ѭ������ 
                int front = q.front();
                if(mouse[front].weight > mouse[maxm].weight)
                    maxm = front;
                mouse[front].rank = group + 1;//ע�⵱��ʧ��������ǡΪ����group+1 
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

//a permutation of 0...N  0��N���û� 
//initial playing order  ��ʼ����˳�� 
