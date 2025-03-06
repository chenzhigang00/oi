#include <iostream>
using namespace std;
const int N = 100010;
typedef pair<long long, long long> PII;
long long n,m,ans;
PII a[N];

//二分条件
bool check(int u){   
    long long sum = 0;
    for (int i =1;i <=n;i++){   //遍历
        if(a[i].second >u)  // 需求比团练次数大的士兵  
            sum += a[i].first;
    }
    if (sum <= m) return true;    // 团队训练花费
    else return false;
}

int main(){
    scanf("%lld %lld", &n,&m);    // n个士兵，m元团练
    long long mx = -N;
    for(int i=1;i<=n;i++){
        long long x,y;
        scanf("%lld %lld", &x, &y);
        a[i].first=x,a[i].second=y;   // 士兵费用，训练次数
        mx = max(mx, y);   // 所有士兵的最大训练次数
    }
    long long l=0,r=mx;   // 左右边界,团练次数从0排到mx

    //团练次数从0到mx，二分查找最小划算的团练次数
    // 寻找右区间左边界版本
    while(r>l){
        long long mid = (l + r) >> 1;
        if (check(mid)) r = mid;    // 满足右区间：团练训练mid次后，各自训练的总花费比继续团练小
        else l = mid + 1;
    }
    
    // 二分结果：团练l次，然后各自训练

    for (int i =1;i<=n;i++){
        if(a[i].second >l)   // 需求比团练次数大的士兵
            ans += a[i].first*(a[i].second -l);    // 除去团练次数，各自训练的费用
    }
    printf("%lld", ans+m*l);    // 加上l次团练费用
    return 0;

}
