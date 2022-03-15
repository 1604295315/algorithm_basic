#include <stdio.h>

const int N = 1010;


int s[N][N];

int main() {
    int a[N][N];
    int n, m, q;

    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            scanf("%d", &a[i][j]);

    s[0][0] = 0;

    for (int i = 0; i <= n; i ++) 
        for (int j = 0; j <= m; j ++) {
            s[i][j] = s[i - 1][j] + s[j][i - 1] -s[i - 1][j - 1] + a[i][j];
        }
    while (q --) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        int x = s[x2][y2] - s[x2][y1] - s[x1][y2] + s[x1][y1];
        printf("%d",x);
    }
    return 0;
}
