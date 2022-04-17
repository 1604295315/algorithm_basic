// AcWing 837. 连通块中点的数量
// 给定一个包含n个点(编号为1~n)的无向图, 初始时图中没有边. 
// 现在要进行m个操作, 操作共三种: 
// 1. C a b 在点a和点b之间连一条边, a和b可能相等
// 2. Q1 a b 询问 a和b 是否在同一个连通块中, a 和 b可能相等
// 3. Q2 a 询问点a所在连通块中点的数量  
#include<iostream>

using namespace std;

const int N = 100010;

int n, m;
int p[N];
int s[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i ++) {
        p[i] = i;
        s[i] = 1;
    }

    while (m --) {
        char op[5];
        int a, b;
        scanf("%s", op);
        if (op[0] == 'C') {
            scanf("%d%d", &a, &b);
            if (find(a) == find(b)) continue;
            s[find(b)] += s[find(a)];
            p[find(a)] = find(b);
            

        }
        else if (op[1] == '1') {
            scanf("%d%d", &a, &b);
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        } else {
            scanf("%d", &a);
            printf("%d\n", s[find(a)]);
        }
    }
    return 0;
}