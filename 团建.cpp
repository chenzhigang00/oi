#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

const int N = 2e5+10;
int n, s, a[N], b[N], sum, m, dmax, _, __;
vector<int> atir[N];
vector<int> btir[N];
bool sta[N], visb[N];
void dfs(int u, int d, int w){
    sta[u] = true;
    visb[w] = true;
    dmax = max(dmax, d);
    map<int,int> bk;
    for (int i:atir[u])
        if (!sta[i])
            bk[a[i]] = i;
    
    for (int j:btir[w])
        if (!visb[j] && bk[b[j]])
            dfs(bk[b[j]],d+1,j);
    // for(int i: atir[u]){
    //     for(int j:btir[w]){
    //         if(a[i] == b[j] && !sta[i] && !visb[j]){
    //             dfs(i,d+1,j);
    //         }
    //     }
    // }
}

int main(){
    cin >> n >> m;
    for (int i = 1; i<=n;i++){
        cin >> a[i];
    }
    for (int i = 1; i<=m;i++){
        cin >> b[i];
    }

    for (int i = 1; i <n;i++){
        cin >> _ >> __;
        atir[_].push_back(__);
        atir[__].push_back(_);
    }
    for(int i = 1; i<m;i++){
        cin >> _ >> __;
        btir[_].push_back(__);
        btir[__].push_back(_);
    }
    if (a[1]==b[1]){
        dfs(1,1,1);
    }
    cout << dmax << endl;
    return 0;
}

