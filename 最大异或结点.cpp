#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 1e5+10;

unordered_map<int , unordered_map<int,int>> graph;
unordered_map<int,int> record;

// N �ǽ������nums[] �ǽ��Ȩ��
int nums[N], tree[N*32][2]; // Ȩ�� �� 0-1 trie

int n,idx,res;     // idx��trie����ţ� res ��������ֵ

void insert(int id){   // id��Ҫ����Ľ��id
    int x = nums[id], root=0;   // x ��Ҫ�ýڵ��Ӧ�Ĳ���Ȩ��
    for(int i =30;i>=0;--i){
        int j = x >> i & 1;   // �Ӹ�λ����λȡ��ÿһλ
        if (!tree[root][j]) tree[root][j] = ++idx;    // ���û������ڵ㣬���½�һ��
        root = tree[root][j];    // root Ϊָ��
        if (i==0) record[root] = id;        // ��¼trieҶ�ӽڵ��Ӧ�������id
    }
}

bool query(int id, int root, int len){
    int x = nums[id];
    if(len == -1){    // ���λ
        // ���������͵�ǰ��㲻�������Ϳ��Լ������ֵ
        if(!graph[id].count(record[root]) and !graph[record[root]].count(id)){
            res = max(res, x ^ nums[record[root]]);
            return true;
        }
        return false;
    }
    int i = x >> len & 1;   // �Ӹ�λ����λȡ��ÿһλ
    if(tree[root][i ^ 1]){   // ��һ����֧����
        if(query(id, tree[root][i^1],len-1)) return true;
    }
    if(tree[root][i]) return query(id, tree[root][i], len - 1); 
    return false;
}

signed main(){
    cin >>n;
    for(int i = 0; i < n;++i) cin >> nums[i];   // ����Ȩ��
    for(int i =0; i < n; ++i){
        int x; cin >> x;
        if(x!=-1) graph[x][i] = 1, graph[i][x] = 1;   // �����
    }
    insert(0);
    for(int i =1; i < n; ++i){
        query(i,0,30);
        insert(i);
    }
    cout <<res;   
    return 0;
}





