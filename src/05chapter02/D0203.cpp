// AcWing 154 滑动窗口
// 单调队列优化
// 滑动窗口里的最大值与最小值
// 单调队列

// n k 1e6 ^2 O(nk)
// 单调队列 最小值为队头
#include <stdio.h>

const int N = 1000010;
// 1e6;

int a[N], q[N];
int n,k;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i ++)
        scanf("%d", &a[i]);
// 双指针和滑动窗口
// 单调队列
// 暴力 挖掘 性质
    int hh = 0, tt = -1;
    for (int i = 0; i < n; i ++) {
        // 判断队头是否已经滑出窗口
        // 空           i-k+1 终点 qhh 该出去了
        if (hh <= tt && i - k + 1 > q[hh])
            hh ++;
        // 新数字比队尾小， 对位无用了， 队尾删掉
        while( hh <= tt && a[q[tt]] >= a[i])
            tt --;
        q[++ tt] = i;
        if (i >= k - 1)
            printf("%d ", a[q[hh]]);
    }
    puts("");
    hh = 0, tt = -1;
    for (int i = 0; i < n; i ++) {
        // 判断队头是否已经滑出窗口
        // 非空           i-k+1 终点 qhh 该出去了
        if (hh <= tt && i - k + 1 > q[hh])
            hh ++;
        // 新数字比队尾小， 对位无用了， 队尾删掉
        while( hh <= tt && a[q[tt]] <= a[i])
            tt --;
        q[++ tt] = i;
        if (i >= k - 1)
            printf("%d ", a[q[hh]]);
    }
    puts("");
    return 0;
}
