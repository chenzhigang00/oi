#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;
long long n, a[N], b[N], ans;

int main(){
    scanf("%lld", &n);
    for (int i = 1; i<=n;i++)
        scanf("%lld", &a[i]);

    for (int i = 1; i<=n/2;i++){    // 差值数组b
        if (a[i] < a[n-i+1])
            b[i] = a[n-i+1] - a[i];
        else if (a[i] > a[n - i + 1])
            b[n - i + 1 ] = a[i] - a[n - i + 1];
    }

    for (int i = 1;i < n; i++){
        long long mn = min(b[i], b[i+1]);   // 相邻两个差值
        b[i] -= mn;
        b[i + 1] -= mn;
        ans += mn;   // 操作次数
        ans += b[i];
    }
    ans += b[n];

    printf("%lld\n", ans);
    return 0;

}