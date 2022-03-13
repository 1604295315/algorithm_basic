#include <iostream>

using namespace std;

const int N = 1000010;

int n;
int q[N],tmp[N];

void merge_sort(int q[], int l, int r)
{
    // O(n*logn)
    // O(n)
    //一个元素或无元素
    if (l >= r)
        return ;
    
    //设置分界点, 分治 
    int mid = l + r >> 1;

    //递归到只有两个数
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);
    
    //排序
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j])
            tmp[k ++] = q[i ++];
        else
            tmp[k ++] = q[j ++];
    }
    //剩下的元素存入
    while (i <= mid)
        tmp[k++] = q[i++];
    while (j <= r)
        tmp[k++] = q[j++];
    //将左右两边合并
    for (i = l, j = 0; i <= r; i++, j++)
        q[i] = tmp[j];
    // for (i = l, j = 0; i <= r; i ++, j ++ ) q[i] = tmp[j];
}

int main(int argc, const char** argv) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    merge_sort(q, 0, n-1);

    for (int i = 0; i < n; i ++)
        printf("%d ",q[i]);
    return 0;
}