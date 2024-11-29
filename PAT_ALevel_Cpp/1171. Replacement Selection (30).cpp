#include <iostream>
#include <queue>
using namespace std;
int N, M, A[100005], index, now;
priority_queue<int, vector<int>, greater<int>> Q1, Q2;
int main(){
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        if (i <= M) Q1.push(A[i]);
    }
    index = M + 1;
    while (Q1.size()) {
        now = Q1.top();//now即为"miniMax" 
        cout << now;
        Q1.pop();
        if(index <= N) {
            if (A[index] < now) Q2.push(A[index]);//只要寻到1个小于miniMax的数，当轮循环结束后Q1大小就会减1 
            else Q1.push(A[index]);
            ++index;
        }
        if (Q1.size()) cout << ' ';
        else {
            swap(Q1, Q2);//如果Q1空，Q2元素最多M个 
            cout << '\n';
        }
    }
    return 0;
}

//external sorting 外部排序
//Replacement Selection sorting algorithm 替换选择排序算法 
