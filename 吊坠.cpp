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
}edg[M*2];    // �ƻ�����

int p[N];   // ���
int find(int x){
    if (p[x]!= x) p[x] = find(p[x]);
    return p[x];
}

// ���������
void kruskal(){
    for(int i = n*(n-1)/2; i >=1;i--){    // �������Ӵ�Сѡ��
        int pa = find(edg[i].a), pb = find(edg[i].b);
        if(pa!=pb){   // �ϲ�
            res += edg[i].w;  // �ۼ�Ȩֵ
            p[pa] = pb;
            cnt ++;   // ����
        }
    }
}

// ����״������Ӵ�  
int cal(string a, string b, int len){   // lenΪ�����ַ�������
    int f[len+10][len+10];    // dp����
    int max=0;    // ��󹫹�������ֵ
    memset(f,0,sizeof f);   // ��ʼ��Ϊ0
    for (int i =1;i<=len;i++){
        for (int j =1;j<=len;j++){
            if(a[i-1] == b[j-1])    // f[i][j]��ʾ��a[i-1]��b[j-1]��β�������������
                f[i][j] = f[i-1][j-1] + 1;
            else
                f[i][j] = 0;
            if (f[i][j]>max) max = f[i][j];
        }
    }
    if (max > len /2) return len /2;    // �������������г��ȳ����ַ������ȣ������ַ�������
    else return max;
}

int main(){
    cin >> n >> m;
    for (int i =1; i<=n;i++){
        cin >> s[i];
        p[i] = i;     // ��ʼ�����鼯
        s[i] += s[i];   // ����һ�����ں���
    }
    int k =1;
    for(int i =1;i<n;i++){
        for(int j =i+1;j<=n;j++){
            edg[k++] = {i,j,cal(s[i],s[j], 2*m)};   // ����ߵ�Ȩֵ��dp�������������У�
        }
    }
    sort(edg+1,edg+1+n*(n-1)/2);   // ����Ȩ��С��������
    kruskal();
    cout << res << endl;
    return 0;
}


