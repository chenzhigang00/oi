#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N =210, M =40010;

int n, m,res,cnt;
string s[N];
struct E{
    int a,b,w;
    bool operator < (E rhs){
        return this->w < rhs.w;
    }
}edg[M*2];    // 破环成链

int p[N];   // 并差集
int find(int x){
    if (p[x]!= x) p[x] = find(p[x]);
    return p[x];
}

// 最“大”生成树
void kruskal(){
    for(int i = n*(n-1)/2; i >=1;i--){    // 排完序后从大到小选边
        int pa = find(edg[i].a), pb = find(edg[i].b);
        if(pa!=pb){   // 合并
            res += edg[i].w;  // 累计权值
            p[pa] = pb;
            cnt ++;   // 边数
        }
    }
}

// 求链状最长公共子串  
int cal(string a, string b, int len){   // len为两倍字符串长度
    int f[len+10][len+10];    // dp数组
    int max=0;    // 最大公共子序列值
    memset(f,0,sizeof f);   // 初始化为0
    for (int i =1;i<=len;i++){
        for (int j =1;j<=len;j++){
            if(a[i-1] == b[j-1])    // f[i][j]表示以a[i-1]和b[j-1]结尾的最长公共子序列
                f[i][j] = f[i-1][j-1] + 1;
            else
                f[i][j] = 0;
            if (f[i][j]>max) max = f[i][j];
        }
    }
    if (max > len /2) return len /2;    // 如果最长公共子序列长度超过字符串长度，返回字符串长度
    else return max;
}

int main(){
    cin >> n >> m;
    for (int i =1; i<=n;i++){
        cin >> s[i];
        p[i] = i;     // 初始化并查集
        s[i] += s[i];   // 复制一份贴在后面
    }
    int k =1;
    for(int i =1;i<n;i++){
        for(int j =i+1;j<=n;j++){
            edg[k++] = {i,j,cal(s[i],s[j], 2*m)};   // 放入边的权值（dp求解最长公共子序列）
        }
    }
    sort(edg+1,edg+1+n*(n-1)/2);   // 按边权从小到大排序
    kruskal();
    cout << res << endl;
    return 0;
}


