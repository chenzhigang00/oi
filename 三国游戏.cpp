#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N =1e5+10;

int a[N], b[N], c[N], t[N], n;

int get(int *x, int *y, int *z){
    for(int i =1;i <=n;i++){
        t[i] = x[i] - y[i]-z[i];   // 贡献
    }
    sort(t+1, t+1+n, greater<>());   // 贡献从大到小排序
    for(int i =1; i <=n;i++){
        t[i] += t[i-1];
        if (t[i] <=0) return i-1;    // 直到不能获胜为止
    }
    return n;
}

signed main(){
    cin >> n;
    for(int i =1;i<=n;i++) cin >> a[i];
    for(int i =1; i <= n;i++) cin >> b[i];
    for(int i =1; i <= n;i++) cin >> c[i];
    int res = max({get(a,b,c), get(b,a,c), get(c,a,b)});
    cout << (res == 0 ? -1:res) << endl;
    return 0;
}
