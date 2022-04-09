// AcWing 单调栈
//  3 4  2 7 5
// -1 3 -1 2 2
// 找出每个数左边离他最近且比它小的数是什么

#include <iostream>

using namespace std;

const int N = 100010;

int n;
int stk[N], tt;
// 全局变量默认初始化为0;
int main() {
    // ios::sync_with_stdio(false);
    // cin >>  n;

    // cin.tie(0);
    scanf("%d", &n);
    int x;
    // O(n);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &x);
        while (tt && stk[tt] >= x) tt --;
        if (tt) printf("%d ", stk[tt]);
        else    printf("-1 ");
        stk[ ++ tt] = x;
    }
    return 0;
}

// void init() {
//     tt = 0;
// }
// void push(int x) {
//     stk[++tt] = x;
// }

// int pop() {
//     return stk[tt--];
// }

