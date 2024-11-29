#include <iostream> //̰�ġ�Ѱ�ұ��Լ�����Զ�ģ����ܹ������������֮��ļ���վ�������ǵ��ͼۡ� 
#include <algorithm>//����ҵ��˸��ͼ۸���ͼۣ��ͼ��͵��պ��ܵ����Ǹ�����վ�ľ�����ͣ�Ȼ��ȥ�Ǹ����ͼ۸�ļ���վ��
#include <vector>   //����Ҳ������͵ģ����Ҿ����ܵ͵��ͼ۵ļ���վ���ڵ�ǰ����վ������֮���ȥ����Ϊ��Ҫ��·����ʹ�õľ������ǵͼ۵��ͣ���Ȼû�бȵ�ǰ���ͼ۸���ˣ���������ӵ����ֵ�������ܱ�֤������󻯣���֤���ľ���ʹ�õ��Ǳ��˵��͡�
using namespace std;
const int inf = 99999999;
struct station {
    double price, dis;
};
bool cmp1(station a, station b) {
    return a.dis < b.dis;
}
int main() {
    double cmax, d, davg;
    int n;
    scanf("%lf%lf%lf%d", &cmax, &d, &davg, &n);
    vector<station> sta(n + 1);//����վ��Ϣ 
    sta[0] = {0.0, d};//�յ����(0��0.0д�����ԣ�0��ת��0.0) 
    for(int i = 1; i <= n; i++)
        scanf("%lf%lf", &sta[i].price, &sta[i].dis);
    sort(sta.begin(), sta.end(), cmp1);
    double nowdis = 0.0, maxdis = 0.0, nowprice = 0.0, totalPrice = 0.0, leftdis = 0.0;//nowdis��ʾ��ǰ���ڵľ��룬maxdis���ܹ�����������룬nowprice�ǵ�ǰ��վ��ļ۸�totalPrice���ܵļ۸�leftdis������ʣ�������ߵľ��� 
    if(sta[0].dis != 0) {//��ʼû���ͣ�������еļ���վ���붼û�е���0�ģ���ô˵������Ҳȥ����
        printf("The maximum travel distance = 0.00");
        return 0;
    } else {
        nowprice = sta[0].price;
    }
    while(nowdis < d) {//ÿ�ε����վ�㶼�Ǿֲ���ʵ�ݵ�վ�� 
        maxdis = nowdis + cmax * davg;
        double minPriceDis = 0, minPrice = inf;
        int flag = 0;
        for(int i = 1; i <= n && sta[i].dis <= maxdis; i++) {
            if(sta[i].dis <= nowdis) continue;
            if(sta[i].price < nowprice) {//�����ҵ��ȵ�ǰ�ͼ۸��͵ĵ�վ�㣬�򾡿����ټӵ�ǰվ����� 
                totalPrice += (sta[i].dis - nowdis - leftdis) * nowprice / davg;//�����Ͷ��˿������ͣ� 
                leftdis = 0.0;
                nowprice = sta[i].price;
                nowdis = sta[i].dis;
                flag = 1;
                break;
            }
            if(sta[i].price < minPrice) {//��¼���ֿ�ȥ������ͼ�վ���ͼۼ������ 
                minPrice = sta[i].price;
                minPriceDis = sta[i].dis;
            }
        }
        if(flag == 0 && minPrice != inf) {//�����Ҳ����ȵ�ǰ�ͼ۸��͵ģ����ҵ��˿�ȥ��Χ���ͼ���͵�վ�㣬�򾡿��ܶ�ӵ�ǰվ����� 
            totalPrice += (nowprice * (cmax - leftdis / davg));
            leftdis = cmax * davg - (minPriceDis - nowdis);
            nowprice = minPrice;
            nowdis = minPriceDis;     
        }
        if(flag == 0 && minPrice == inf) {//����û�ҵ���ȥ��վ�� 
            nowdis += cmax * davg;
            printf("The maximum travel distance = %.2f", nowdis);
            return 0;
        }
    }
    printf("%.2f", totalPrice);
    return 0;
}

//from time to time ��ʱ�� 
