// 一维差分(前缀和的逆运算)
// ```
// 给区间[l, r]中的每个数加上c：B[l] += c, B[r + 1] -= c
// ```


// 就是变相记录修改过程，在输出的时候统一修改了。！！！！
#include <stdio.h>

const int N = 100010;

int n, m;
int a[N], s[N], b[N];

void insert(int l, int r, int c) {
    b[l] += c;
    b[r + 1] -= c;
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i ++)
        scanf("%d",&a[i]);

    // 差分数组生成: O(n^2)
    // for (int i = 1; i <= n; i ++) {
    //     s[i] = s[i - 1] + a[i]; //求前缀和
    //     for (int j = i; j >= 0; j --)
    //         b[i] += a[j];
    // }
    for (int i = 1; i <= n; i ++) insert(i, i, a[i]);
    /*
        1 1 b[1] += a[1] b[2] -= a[1]
        2 2 b[2] += a[2] b[3] -= a[2]
        b[1] = a[1]
        b[2] = a[2] - a[1]
        怎么可以这么妙
    */

    int l, r, c;
    while (m --) {
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);
    }

    // 求一下原来的数组 对差分数组求前缀和
    for (int i = 1; i <= n; i ++) b[i] += b[i - 1];
        

    for (int i = 1; i <= n; i ++) printf("%d ", b[i]);
    return 0;
}