#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;
vector<vector<int>> s(10);    // 0-9 
int n,a,b;

int main(){
    cin >> n;
    for(int i =0; i < n; i++){
        cin >> a>>b;
        s[a].push_back(b);
    }
    for(int i = 0; i < 10; i++){
        sort(s[i].begin(),s[i].end());   // 代价从小到大
    }

    LL res = 0, c=n/10;
    for(int i =0; i < 10;i ++){
        if (s[i].size() < c) continue;   // 某数的代价次数小于等于平均，必须保留

        for(int j =0; j < s[i].size()-c; j++){   // 转换多出来的
            res += s[i][j];   // 累计代价
        }
    }

    cout << res << endl;
    return 0;

}








