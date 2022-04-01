// 二维差分
// ```
// 给以(x1, y1)为左上角，(x2, y2)为右下角的子矩阵中的所有元素加上c：
// S[x1, y1] += c, S[x2 + 1, y1] -= c, S[x1, y2 + 1] -= c, S[x2 + 1, y2 + 1] += c
// ```

/*
    原矩阵 a[i][j]
    差分矩阵 b[i][j] 
    a[i][j] = b[0][0] + ... + b[i][j] 
    b[x1][y1] += c;
    b[x2 - 1][y1] -= c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y2 + 1] += c;
*/
#include <stdio.h>

const int N = 1010;

int a[N][N], b[N][N];

int n, m, q;

void insert(int x1, int y1, int x2, int y2, int c) {
    b[x1][y1] += c;
    b[x2 +1][y1] -= c;
    b[x1][y2 +1]-= c;
    b[x2 + 1][y2 +1]+= c;
}

int main() {
    scanf("%d%d%d", &n, &m, &q);

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            scanf("%d", &a[i][j]);

    for (int i = 1; i <= n; i ++)
        for (int j = 0; j <= m; j ++)
            insert(i, j, i, j, a[i][j]);

    int x1, y1, x2, y2, c;
    while (q --) {
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
        insert(x1, y1, x2, y2, c);
    }

    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= m; j ++)
        {    
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
            printf("%d ", b[i][j]);
        }    
        printf("\n");
    }
    return 0;
}