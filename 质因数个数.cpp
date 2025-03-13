#include <iostream>
using namespace std;
typedef long long LL;
LL n;

int main()
{
    scanf("%lld", &n);

    LL res =0;
    for (LL i=2;i <= n/i;i++)
    {
        if (n % i == 0)
        {
            res++;
            while(n % i == 0) n /= i;
        }
    }

    if (n > 1) res++;

    cout << res << endl;
    return 0;


}





