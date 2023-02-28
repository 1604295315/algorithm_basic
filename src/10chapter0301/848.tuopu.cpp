// 拓扑排序

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010;

int n, m;
// 邻接表法存储图
int h[N], e[N], ne[N], idx;
int q[N], d[N];
// 数组模拟队列

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int topsort() {
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i ++) {
        if (d[i] == 0) // !d[i]
            q[++ tt] = i;
    }

    while (hh <= tt) {
        int t = q[hh ++];

        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            d[j] --;
            if (!d[j])  q[++ tt] = j;
        }
    }

    return tt == n - 1; // 是否进入n个点
}

int main() {
    cin >> n >> m;

    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b] ++;
    }

    if (topsort()) {
        for (int i = 0; i < n; i ++) {
            cout << q[i] << ' ';
        }
        puts("");
    } else
        puts("-1");
    return 0;
}