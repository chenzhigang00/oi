#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 1e5+10;

unordered_map<int , unordered_map<int,int>> graph;
unordered_map<int,int> record;

// N 是结点数，nums[] 是结点权重
int nums[N], tree[N*32][2]; // 权重 和 0-1 trie

int n,idx,res;     // idx是trie结点编号， res 是最大异或值

void insert(int id){   // id是要处理的结点id
    int x = nums[id], root=0;   // x 是要该节点对应的插入权重
    for(int i =30;i>=0;--i){
        int j = x >> i & 1;   // 从高位到低位取出每一位
        if (!tree[root][j]) tree[root][j] = ++idx;    // 如果没有这个节点，就新建一个
        root = tree[root][j];    // root 为指针
        if (i==0) record[root] = id;        // 记录trie叶子节点对应的树结点id
    }
}

bool query(int id, int root, int len){
    int x = nums[id];
    if(len == -1){    // 最低位
        // 如果这个结点和当前结点不相连，就可以计算异或值
        if(!graph[id].count(record[root]) and !graph[record[root]].count(id)){
            res = max(res, x ^ nums[record[root]]);
            return true;
        }
        return false;
    }
    int i = x >> len & 1;   // 从高位到低位取出每一位
    if(tree[root][i ^ 1]){   // 另一个分支存在
        if(query(id, tree[root][i^1],len-1)) return true;
    }
    if(tree[root][i]) return query(id, tree[root][i], len - 1); 
    return false;
}

signed main(){
    cin >>n;
    for(int i = 0; i < n;++i) cin >> nums[i];   // 读入权重
    for(int i =0; i < n; ++i){
        int x; cin >> x;
        if(x!=-1) graph[x][i] = 1, graph[i][x] = 1;   // 读入边
    }
    insert(0);
    for(int i =1; i < n; ++i){
        query(i,0,30);
        insert(i);
    }
    cout <<res;   
    return 0;
}





