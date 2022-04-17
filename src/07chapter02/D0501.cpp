// AcWing 836. 合并集合
// 一共有n个数, 编号是1~n, 最开始每个数各自在一个集合中. 
// M a b
// Q a b

#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int p[N];

// 返回x的祖宗节点 + 路径压缩
int find(int x) { // 返回x 所在集合的编号
    if (p[x] != x)  p[x] = find(p[x]);
    return p[x];
    // return p[x] == x ? x : p[x] = find(p[x]);
}
// %*c [^]
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) p[i] = i;
    while (m --) {
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        if (op[0] == 'M') p[find(a)] = find(b);
        else {
            if(find(a) == find(b)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}