// 796. 子矩阵和  较为抽象
// 二维前缀和
// `int a[N][N], s[N][N];`
// `s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];`
// `s[x2][y2] ~ s[x1][j1] = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 -1] + s[x1 - 1][y1 -1];`

#include <iostream>

using namespace std;

const int N = 1e4 + 10;

int m, n, q;
int a[N][N], s[N][N];

int main() {
    cin >> m >> n >> q;
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++)
            scanf("%d", &a[i][j]);

    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++)
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
    
    int x1, y1, x2, y2;
    while (q --) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        int x = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 -1] + s[x1 -1][y1 - 1];
        printf("%d\n", x);
    }
    return 0;

}