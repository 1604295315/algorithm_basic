// 差分数组
// 
#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N];
// a是原数组, b是差分数组
// b[1] = a[1]
// b[2] = a[1] - a[2]
// a[2] = b[1] + b[2]

// 构造过程
// b[1] = b[1] + a[1]
// b[2] = b[2] - a[1] + a[2]
// b[3] = b[3] - a[2] + a[3]
// b[4] = b[4] - a[3]
// 构造 insert(i,i,a[i]);

void insert(int l, int r, int val) {
    b[l] += val;
    b[r + 1] -= val;
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);

    for (int i = 1; i <= n; i ++) insert(i, i, a[i]);

    int l, r, val;
    while (m --) {
        scanf("%d%d%d", &l, &r, &val);
        insert(l, r, val);
    }
    for (int i = 1; i <= n; i ++)
        a[i] = a[i - 1] + b[i];
    
    for (int i = 1; i <= n; i ++) {
        (i - 1) && printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}