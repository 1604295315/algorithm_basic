#include <stdio.h>

const int N = 1e6 + 10;

int n;
int q[N];

void quick_sort(int q[], int l, int r)
{
    if (l >= r)
        return ;
    
    int i = l - 1, j = r + 1;
    int x = q[l + r >> 1 ];
    while(i < j)
    {
        while (q[ ++ i] < x);
        while (q[ -- j] > x);
        if(i < j) 
        {
            int temp = q[i];
            q[i] = q[j];
            q[j] = temp;
        }
    }
    quick_sort(q,l,j);
    quick_sort(q, j+1, r); 
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++)
        scanf("%d", &q[i]);
    
    quick_sort(q, 0, n-1);

    for (int i = 0; i < n; i ++)
    {
        i && printf(" ");
        printf("%d", q[i]);
    }
    printf("\n");
    return 0;
}

// int main(int argc, const char** argv) {
//     if(argc <= 1)
//         printf("0 argc\n");
//     else
//         printf("%d args\n", argc - 1);
//     return 0;
// }
/*
int Partition(int q[], int l, int r) {
    int pivot = q[l];
    while (l < r)
    {
        while( l < r && q[r] >= pivot) -- r;
        q[l] = q[r];
        while( l < r && q[l] <= pivot) ++ l;
        q[r] = q[l];
    }
    q[l] = pivot;
    return l;
}

void QuickSort(int q[], int l, int r) {
    if (l < r) {
        int pivotpos = Partition(q, l, r);
        QuickSort(q, l, pivotpos - 1);
        QuickSort(q, pivotpos + 1, r);
    }
}

*/