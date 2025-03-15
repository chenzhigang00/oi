// #include <bits/stdc++.h>
// using namespace std;
// struct qwq{
//     int v;
//     int w;
//     int nxt;
// }edge[2000001];
// int head[2000001];
// int cnt=-1;
// void add(int u, int v, int w){
//     edge[++cnt].nxt=head[u];
//     edge[cnt].v=v;
//     edge[cnt].w=w;
//     head[u]=cnt;
// }

// int sum[2000001];
// void dfs(int x, int fa){    //预处理
//     for(int i=head[x];~i;i=edge[i].nxt){
//         int v = edge[i].v;
//         int w = edge[i].w;
//         if(v!=fa){
//             sum[v]=sum[x]^w;
//             dfs(v, x);
//         }
//     }
// }

// struct trie{
//     int ch[2];
// }t[2000001];
// int tot;
// void build(int val, int x){
//     for(int i=(1<<30);i;i>>=1){
//         bool c=val&i;
//         if(!t[x].ch[c])
//             t[x].ch[c] = ++tot;
//         x = t[x].ch[c];
//     }
// }

// int query(int val, int x){
//     int ans = 0;
//     for(int i=(1<<30);i;i>>=1){
//         bool c=val&i;
//         if(t[x].ch[!c]){
//             ans += i;
//             x = t[x].ch[c];
//         }
//         else
//             x = t[x].ch[!c];
//     }
//     return ans;
// }

// int main(){
//     memset(head, -1, sizeof(head));
//     int n;
//     scanf("%d", &n);
//     for(int i =1;i<n;++i){
//         int u, v, w;
//         scanf("%d%d%d", &u, &v, &w);
//         add(u,v,w);
//         add(v,u,w);
//     }
//     dfs(1,-1);   // 预处理出每一个节点到根的异或和
//     for(int i =1;i<=n; ++i) build(sum[i],0);
//     int ans = 0;
//     for(int i =1;i<=n;++i){
//         ans = max(ans,query(sum[i],0));
//     }
//     printf("%d\n", ans);
// }




