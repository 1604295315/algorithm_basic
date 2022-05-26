// AcWing 839. 模拟堆
// 五种操作 : 
// l x : 插入一个数x
// P M : 输出当前集合的最小值
// D M : 删除当前集合中的最小值(当最小值不唯一时， 删除最早插入的最小值)
// D k : 删除第k个插入的数
// C k x : 修改第k个插入的数, 将其变为x
#include <iostream>
#include <string.h>

using namespace std;

const int N = 100010;
int n, m;
int h[N], ph[N], hp[N], s;
// ph 第k个插入到点是那个点，其下标
// hp 堆里面 一个点 是第几个插入的点

void heap_swap(int a, int b) {
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u) {
    int t = u;
    if (u * 2 <= s && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= s && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t) {
        heap_swap(u, t);
        down(t);
    }
}

void up(int u) {
    while (u / 2 && h[u/2] > h[u]) {
        heap_swap(u / 2, u);
        u /= 2;
    }
}
int main() {
    int n, m = 0;
    scanf("%d%d", &n);
    while (n --) {
        char op[10];
        int k, x;

        scanf("%s", op);
        if (!strcmp(op,"I")) {
            scanf("%d", &x);
            s ++;
            m ++;
            ph[m] = s, hp[s] = m;
            h[s] = x;
            up(s);
        } else if (!strcmp(op, "PM")) {
            printf("%d\n", h[1]);
        } else if (!strcmp(op, "DM")) {
            heap_swap(1,s);
            s --;
            down (1);
        } else if (!strcmp(op, "D")) {
            scanf("%d", &k);
            k = ph[k];
            heap_swap(k, s);
            s --;
            down(k), up(k);
        } else {
            scanf("%d%d", &k, &x);
            k = ph[k];
            h[k] = x;
            down(k), up(k);
        }
    }
    return 0;
}