#include <iostream>
#include <vector>

using namespace std;

const int N = 100010;


vector<int> fac[N];    

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

void solve(int n)
{
    for(auto re:primes)
    {
        for(int j=re;j<=n;j+=re)
        {
            fac[j].push_back(re);
        }
    }
    cout << fac[n].size() << endl;

}

int main()
{
    int n ;
    cin >> n;
    get_primes(n);
    solve(n);
    return 0;
}
