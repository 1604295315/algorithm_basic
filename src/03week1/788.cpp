// AcWing 788.逆序对的数量
// tips: 归并排序
// 思路 -> 抽象 -> 代码

#include <stdio.h>

typedef long long LL;

const int N = 100010;

int n;
int q[N], tmp[N];
// 逆序对 最大值 n * (1 + n - 1)/2
LL result = 0;

LL merge_sort(int q[], int l, int r) {
    if (l >= r) return 0;
    
    int mid = l + r >> 1;
    LL res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);

    // 各处两边\，如何快速算出s1~sm
    // 归并过程
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) {
            tmp[k ++] = q[i ++];
        } else {
            tmp[k ++] = q[j ++];
            res += mid -i + 1;
        }
    }

    // 扫尾
    while (i <= mid) tmp[k ++] = q[i ++];
    while (j <= r) tmp[k ++] = q[j ++];

    // 把tmp 放回 q[] 物归原主
    for (i = l, j = 0; i <= r; i ++, j ++ ) 
        q[i] = tmp[j];
    return res;


}

void merge_sort1(int q[], int l, int r)
{
    int tmp[r + 1] = {0};
    if (l >= r) return;

    int mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);

    // 两边合并
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (q[i] <= q[j]) tmp[k ++ ] = q[i ++ ];
        else tmp[k ++ ] = q[j ++ ];
    // 其余于元素归入 tmp
    while (i <= mid) tmp[k ++ ] = q[i ++ ];
    while (j <= r) tmp[k ++ ] = q[j ++ ];
    // 数据放回q[] 物归原主
    for (i = l, j = 0; i <= r; i ++, j ++ ) 
        q[i] = tmp[j];
}

int main() {
    scanf("%d", &n);
    
    for (int i = 0; i < n; i ++)
        scanf("%d", &q[i]);

    LL x = merge_sort(q, 0, n -1);
    printf("%lld\n", x);
    return 0;
}