#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 100010;

int primes[N];
bool st[N];       // ������״̬�������
int cnt;

void get_primes(int n ){       // ����ɸ����
    for(int i = 2; i <=n; i++){
        if(!st[i])
            primes[cnt++] = i;
        for(int j =0;primes[j]<=n/i;j++){
            st[primes[j]*i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int t;
int dp[N];     // ľͷ����Ϊ nʱ�ܷ�Ӯ

int main(){
    get_primes(100000);

    dp[0]=0,dp[1]=0;
    for(int i =2;i<=1e5;i++){
        bool flag = false;
        for(int j =0; primes[j] <= i && j < cnt; j++){     //ö������С��i������
            if(dp[i-primes[j]] == 0){       //���dp[i-primes[j]] == 0,˵���������ˣ���ô�Լ���Ӯ��
                dp[i] = 1;
                flag = true;
                break;
            } 
        }
        if (!flag) dp[i] = 0;
    }
    
    cin >> t;
    while(t--){
        int x;
        scanf("%d", &x);
        if (dp[x])
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }
    return 0;
}



