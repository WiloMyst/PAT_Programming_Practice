#include <iostream> //贪心。寻找比自己距离远的，到能够到达的最大距离之间的加油站，看他们的油价。 
#include <algorithm>//如果找到了更低价格的油价，就加油到刚好能到达那个加油站的距离的油，然后去那个更低价格的加油站。
#include <vector>   //如果找不到更低的，就找尽可能低的油价的加油站，在当前加油站加满油之后过去。因为想要让路程上使用的尽可能是低价的油，既然没有比当前更低价格的了，就让油箱加到最大值，这样能保证利益最大化，保证最大的距离使用的是便宜的油。
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
    vector<station> sta(n + 1);//加油站信息 
    sta[0] = {0.0, d};//终点城市(0和0.0写法都对，0会转成0.0) 
    for(int i = 1; i <= n; i++)
        scanf("%lf%lf", &sta[i].price, &sta[i].dis);
    sort(sta.begin(), sta.end(), cmp1);
    double nowdis = 0.0, maxdis = 0.0, nowprice = 0.0, totalPrice = 0.0, leftdis = 0.0;//nowdis表示当前所在的距离，maxdis是能够到达的最大距离，nowprice是当前的站点的价格，totalPrice是总的价格，leftdis是油箱剩余油能走的距离 
    if(sta[0].dis != 0) {//开始没有油，如果所有的加油站距离都没有等于0的，那么说明车哪也去不了
        printf("The maximum travel distance = 0.00");
        return 0;
    } else {
        nowprice = sta[0].price;
    }
    while(nowdis < d) {//每次到达的站点都是局部最实惠的站点 
        maxdis = nowdis + cmax * davg;
        double minPriceDis = 0, minPrice = inf;
        int flag = 0;
        for(int i = 1; i <= n && sta[i].dis <= maxdis; i++) {
            if(sta[i].dis <= nowdis) continue;
            if(sta[i].price < nowprice) {//当轮找到比当前油价更低的的站点，则尽可能少加当前站点的油 
                totalPrice += (sta[i].dis - nowdis - leftdis) * nowprice / davg;//这题油多了可以退油？ 
                leftdis = 0.0;
                nowprice = sta[i].price;
                nowdis = sta[i].dis;
                flag = 1;
                break;
            }
            if(sta[i].price < minPrice) {//记录当轮可去的最低油价站的油价及其距离 
                minPrice = sta[i].price;
                minPriceDis = sta[i].dis;
            }
        }
        if(flag == 0 && minPrice != inf) {//当轮找不到比当前油价更低的，但找到了可去范围内油价最低的站点，则尽可能多加当前站点的油 
            totalPrice += (nowprice * (cmax - leftdis / davg));
            leftdis = cmax * davg - (minPriceDis - nowdis);
            nowprice = minPrice;
            nowdis = minPriceDis;     
        }
        if(flag == 0 && minPrice == inf) {//当轮没找到可去的站点 
            nowdis += cmax * davg;
            printf("The maximum travel distance = %.2f", nowdis);
            return 0;
        }
    }
    printf("%.2f", totalPrice);
    return 0;
}

//from time to time 不时地 
