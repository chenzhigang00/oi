#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N=200010,M=N*2;

// head, edge, next edge, index
int h[2][N], e[2][M], ne[2][M], idx;    // ���ڴ洢���������ڽӱ�
int w1[N],w2[N];    // �ֱ�洢��������������Ȩֵ
int n,m;            // �����������

// ���� i �������һ���� a->b
void add(int i, int a, int b){
    e[i][idx] = b;
    ne[i][idx] = h[i][a];
    h[i][a] = idx++;
}

// ���������������
int dfs(int u1, int u2, int fa1, int fa2){
    int res = 0;
    unordered_map<int, int> hs;

    // ������һ�������ӽ��
    for(int i = h[0][u1]; i != -1; i = ne[0][i]){
        int j = e[0][i];
        if (j == fa1) 
            continue;
        hs[w1[j]] = j;
    }

    // �����ڶ��������ӽ��
    for (int i = h[1][u2]; ~i; i = ne[1][i]){
        int j = e[1][i];
        if (j == fa2)
            continue;

        // �������Ȩֵ��ͬ�Ľ�㣬���ܹ�������������
        if (hs.count(w2[j])){
            // ���������������Ϊ������µ������·������
            res = max(res, dfs(hs[w2[j]], j, u1, u2));
        }
    }
    
    // ���صĽ����Ҫ���ϵ�ǰ���
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


