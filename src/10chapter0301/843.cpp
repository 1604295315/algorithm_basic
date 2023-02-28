// n−皇后问题是指将n个皇后放在 n x n的国际象棋棋盘上, 使得皇后不能相互攻击到, 即任意两个皇后都不能处于同一行、同一列或同一斜线上. 
// 现在给定整数 n , 请你输出所有的满足条件的棋子摆法.
// 剪枝，11~，不合法直接回溯，不再递
// 第一种搜索顺序
#include <iostream>

using namespace std;

const int N = 20;

int n;
char g[N][N];
int col[N], dg[N], udg[N];

void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; i ++) puts(g[i]);
        puts("");
        return ;
    }
    for (int i = 0; i < n; i ++) {
        if (!col[i] && !dg[u+i] && !udg[ n - u + i]) {
            g[u][i] = 'Q';
            col[i] = dg[u + i] = udg[n - u + i] = true;
            dfs(u + 1);
            col[i] = dg[u + i] = udg[n - u + i] = false;
            g[u][i] = '.';
        }
    }

}

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            g[i][j] = '.';
    dfs(0);
    return 0;
}