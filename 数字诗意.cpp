#include <iostream>
//#include <set>
#include<cmath>

using namespace std;
typedef long long LL;

int n;
//set<LL> S;

int main(){
    // LL t = 1;
    // for (int i = 1; i< 63; ++i)
    //     S.insert(t), t *= 2;
    
    cin >> n;
    int res = 0;
    while(n--){
        LL x;
        cin >> x;
        LL p = log2(x);
        
        if (1ll<<p == x)
            res += 1;
    }

    cout <<res <<endl;

    return 0;
}