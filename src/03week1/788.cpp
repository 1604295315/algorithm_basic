// AcWing 788.逆序对的数量
// tips: 归并排序

#include <stdio.h>

const int N = 100010;
int n;
int q[N];

int merge_sort(int q[], int l, int r) {
    if (l >= r)
        return -1;
    int mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);
    // 各处两边\，
    int count = 0;
    for (int i = l; i <= mid; i ++)
        for (int j = mid + 1; j <= r; j ++)
            if(q[i] > q[j])
                count ++;;
    

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
    // 甚于元素归入 tmp
    while (i <= mid) tmp[k ++ ] = q[i ++ ];
    while (j <= r) tmp[k ++ ] = q[j ++ ];
    // 数据放回q[]
    for (i = l, j = 0; i <= r; i ++, j ++ ) 
        q[i] = tmp[j];
}

int main() {
    scanf("%d", &n);
    
    for (int i = 0; i < n; i ++)
        scanf("%d", &q[i]);

    int x = merge_sort(q, 0, n -1);
    printf("%d\n", x);
    return 0;
}