#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5+10;
int p[N],c[N];
long long a[100*N];

int main(){
    int n;
    // cout << n;    // ��Ч���ֵ
    long long s;
    cin >> n >> s;
    int max_t = 0;          // ��¼����ʿ�������ĵ���ѵ������
    long long ans = 0;
    long long sum_cost = 0;
    for(int i =1;i<=n;i++){
        cin >> p[i]>>c[i];
        sum_cost += p[i];   // ����ʿ��ÿ�������Ļ����ܺ�
        a[c[i]]+=p[i];      // ������Ҫ������c[i]����ʿ��ÿ�������Ļ����ܺ�
        max_t = max(max_t,c[i]);
    }

    for(int i=1;i<=max_t;i++){
        if(sum_cost>s){
            ans+=s;
        }
        else{
            ans += sum_cost;
        }
        sum_cost -= a[i];   // ������i����ʿ���������ѵ��
    }

    cout << ans<<endl;
    return 0;
    
    // int p[n + 10], c[n+10];
    // for (int i = 1; i <= n; i++){
    //     cin >> p[i] >> c[i];
    // }

    // int cost = 0;

}