#include <stdio.h>

const int N = 1010;

int n, m, q;
int s[N][N], a[N][N];

int main() {
    
    scanf("%d%d%d", &n, &m, &q);

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            scanf("%d", &a[i][j]);

    s[0][0] = 0;
    for (int i = 1; i <= n; i ++) 
        for (int j = 1; j <= m; j ++) 
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j]; 
            //求前缀和
    
    int x1, y1, x2, y2;
    while (q --) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        int x = s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1];
        //算部分和
        printf("%d\n", x);
    }

    return 0;
}