#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N=200010,M=N*2;

// head, edge, next edge, index
int h[2][N], e[2][M], ne[2][M], idx;    // 用于存储两棵树的邻接表
int w1[N],w2[N];    // 分别存储两棵树各个结点的权值
int n,m;            // 结点数，边数

// 给第 i 棵树添加一条边 a->b
void add(int i, int a, int b){
    e[i][idx] = b;
    ne[i][idx] = h[i][a];
    h[i][a] = idx++;
}

// 深度优先搜索函数
int dfs(int u1, int u2, int fa1, int fa2){
    int res = 0;
    unordered_map<int, int> hs;

    // 遍历第一棵树的子结点
    for(int i = h[0][u1]; i != -1; i = ne[0][i]){
        int j = e[0][i];
        if (j == fa1) 
            continue;
        hs[w1[j]] = j;
    }

    // 遍历第二棵树的子结点
    for (int i = h[1][u2]; ~i; i = ne[1][i]){
        int j = e[1][i];
        if (j == fa2)
            continue;

        // 如果存在权值相同的结点，就能够继续向下搜索
        if (hs.count(w2[j])){
            // 计算以这两个结点为起点往下的最长公共路径长度
            res = max(res, dfs(hs[w2[j]], j, u1, u2));
        }
    }
    
    // 返回的结果需要加上当前结点
    return res + 1;
}

int main(){
    scanf("%d%d", &n,&m);
    memset(h,-1,sizeof(h));
    for (int i = 1; i<=n; i ++) scanf("%d", &w1[i]);
    for (int i = 1; i<=m; i ++) scanf("%d", &w2[i]);

    for (int i = 0; i < n - 1; i ++){
        int a, b;
        scanf("%d%d", &a, &b);
        add(0,a,b);
        add(0,b,a);
    }

    for (int i = 0; i < m - 1; i ++){
        int a, b;
        scanf("%d%d", &a, &b);
        add(1,a,b);
        add(1,b,a);
    }

    int res = 0;
    if (w1[1]==w2[1]){
        res = dfs(1,1,0,0);
    }
    printf("%d\n", res);

    return 0;
}


