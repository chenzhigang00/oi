#include <iostream>
using namespace std;
const int N = 100010;
typedef pair<long long, long long> PII;
long long n,m,ans;
PII a[N];

//��������
bool check(int u){   
    long long sum = 0;
    for (int i =1;i <=n;i++){   //����
        if(a[i].second >u)  // ����������������ʿ��  
            sum += a[i].first;
    }
    if (sum <= m) return true;    // �Ŷ�ѵ������
    else return false;
}

int main(){
    scanf("%lld %lld", &n,&m);    // n��ʿ����mԪ����
    long long mx = -N;
    for(int i=1;i<=n;i++){
        long long x,y;
        scanf("%lld %lld", &x, &y);
        a[i].first=x,a[i].second=y;   // ʿ�����ã�ѵ������
        mx = max(mx, y);   // ����ʿ�������ѵ������
    }
    long long l=0,r=mx;   // ���ұ߽�,����������0�ŵ�mx

    //����������0��mx�����ֲ�����С�������������
    // Ѱ����������߽�汾
    while(r>l){
        long long mid = (l + r) >> 1;
        if (check(mid)) r = mid;    // ���������䣺����ѵ��mid�κ󣬸���ѵ�����ܻ��ѱȼ�������С
        else l = mid + 1;
    }
    
    // ���ֽ��������l�Σ�Ȼ�����ѵ��

    for (int i =1;i<=n;i++){
        if(a[i].second >l)   // ����������������ʿ��
            ans += a[i].first*(a[i].second -l);    // ��ȥ��������������ѵ���ķ���
    }
    printf("%lld", ans+m*l);    // ����l����������
    return 0;

}
