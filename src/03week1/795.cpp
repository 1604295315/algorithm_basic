// 795. 前缀和
// 一种特殊的方法
// 空间换时间 快速得到某一区域的数值和
// int a[], s[]

#include <stdio.h>

const int N = 1e6 + 10;

int n;
int a[N], s[N];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; i ++)
        s[i] = s[i - 1] + a[i];

    int m;
    int l, r;
    scanf("%d", &m);

    while (m --) {
        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);
    }

    return 0;
}