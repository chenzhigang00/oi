#include <bits/stdc++.h>
using namespace std;
const int N =1e5+10; int a[N], son[N*31][2], idx;
void insert(int x){     //Trie插入
    int p=0;
    for(int i =30;i>=0;i--){
        int u = (x>>i) & 1;
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
}

int query(int x){
    int p=0,ans=0;
    for(int i =30;i>=0;i--){    //从高到低枚举数位
        int u = (x>>i) & 1;
        if(son[p][!u])  ans=ans*2+1, p=son[p][!u];  // 尽量枚举不一样的数位
        else ans*=2, p = son[p][u];
    }
    return ans;
}

int main(){
    int n ;
    scanf("%d", &n);
    for(int i =1;i<=n;i++) scanf("%d", &a[i]), insert(a[i]);
    int ans = 0;
    for(int i=1;i<=n;i++)
        if(query(a[i])>ans) ans = query(a[i]);
    printf("%d\n", ans);
    return 0;

}



