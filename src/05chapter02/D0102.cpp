// 双链表
#include <iostream>

using namespace std;

const int N = 100010;

// struct Node {
//     int e,l,r;
// }nodes[N];
int m;
int e[N], r[N], l[N];
int idx;

// 初始化
void init() {
    // 0表示左端点 1表示右端点
    r[0] = 1, l[1] = 0;
    idx = 2;
}

// 插入一个点 在k的有点插入一个点
void add(int k,int x) {
    // k 右
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;

    l[r[k]] = idx;
    r[k] = idx;
    idx ++;
// 或者k的左边插入一个点==> l[k] 的右边插入一个点
    // k 左
    // l[k] idx k r[k]
    // e[idx] = x;
    // r[idx] = k;
    // l[idx] = l[k];

    // r[l[k]] = idx;
    // l[k] = idx;
    // idx ++;
}

void remove(int k) {
    r[l[k]] = r[k];
    l[r[k]] = l[k];
    // nodes[nodes[k].l].r = nodes[k].r;
}

// 最短路 最小生成树 <== 数组模拟邻接表 
// 关于图论

int main() {
    cin >> m;
    char op;
    while (m --) {
        cin >> op;
        switch (op) {

        }
    }
}