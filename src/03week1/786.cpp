#include <iostream>

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
