// 贪心
#include <iostream>
#include <cmath>

#define int long long
using namespace std;
const int N = 1e6 + 11;

int a[N], b[N>>1];
int sum,cnt,j;
signed main(){
    int n ;
    cin >> n;
    for (int i = 1; i <= n;i ++){
        cin >> a[i];
    }

    for (int i =1;i<=n/2;i++){
        b[++j] = a[i] - a[n -i + 1];   // 记录对应差值
    }
    int len =j;
    for (int i =1; i <= len; i++){
        cnt += abs(b[i]);   // 首先操作当前插值
        // if(i!=n){
        if (b[i] > 0 && b[i + 1] > 0){   // 同号，说明方向相同，可以一起操作
            b[i + 1 ] -= min(b[i],b[i+1]);
        }
        if (b[i] < 0 && b[i + 1] < 0){
            b[i + 1] -= max(b[i],b[i+1]);
        }
        // }
    }
    cout << cnt;

    return 0;
}