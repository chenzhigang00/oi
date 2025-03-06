#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5+10;
int p[N],c[N];
long long a[100*N];

int main(){
    int n;
    // cout << n;    // 无效随机值
    long long s;
    cin >> n >> s;
    int max_t = 0;          // 记录所有士兵中最大的单独训练次数
    long long ans = 0;
    long long sum_cost = 0;
    for(int i =1;i<=n;i++){
        cin >> p[i]>>c[i];
        sum_cost += p[i];   // 所有士兵每次升级的花费总和
        a[c[i]]+=p[i];      // 所有需要升级到c[i]级的士兵每次升级的花费总和
        max_t = max(max_t,c[i]);
    }

    for(int i=1;i<=max_t;i++){
        if(sum_cost>s){
            ans+=s;
        }
        else{
            ans += sum_cost;
        }
        sum_cost -= a[i];   // 升满到i级的士兵无须参与训练
    }

    cout << ans<<endl;
    return 0;
    
    // int p[n + 10], c[n+10];
    // for (int i = 1; i <= n; i++){
    //     cin >> p[i] >> c[i];
    // }

    // int cost = 0;

}