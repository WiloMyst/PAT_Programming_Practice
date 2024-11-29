#include <iostream>
using namespace std;
int Msize, n, hashTable[10100];
bool isprime(int num) {
    if(num == 1) return false;
    for(int i = 2; i * i <= num; i++)
        if(num % i == 0) return false;
    return true;
}
void insert(int key) {
    for(int step = 0; step < Msize; step++) {//ע�⣬����̽������̽����ξͿ���ȷ����� 
        int index = (key + step * step) % Msize;//ע��((a%m)+b)%m�ȼ���(a+b)%m 
        if(hashTable[index] == 0) {
            hashTable[index] = 1;
            cout << index % Msize;
            return ;
        }
    }
    cout << '-';
}
int main() {
    cin >> Msize >> n;
    while(!isprime(Msize)) Msize++;
    for(int i = 0; i < n; i++) {
        int key;
        cin >> key;
        if(i != 0) cout << ' ';
        insert(key);
    }
    return 0;
}

//a sequence of һϵ��
//quadratic probe ����̽��
//positive increment ������
//in case ��� 
