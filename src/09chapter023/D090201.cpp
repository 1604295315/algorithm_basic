// 字符串哈希
// 字符串前缀哈希法
// p进制的数
// 给定一个长度为 n 的字符串，再给定 m 个询问，
// 每个询问包含四个整数 l1,r1,l2,r2，
// 请你判断 [l1,r1] 和 [l2,r2] 
// 这两个区间所包含的字符串子串是否完全相同。
// 字符串中只包含大小写英文字母和数字。
#include <iostream>

using namespace std;
// 特型算法
typedef unsigned long long ULL;

const int N = 100010;
const int P = 131;

int n, m;
char str[N];
ULL h[N], p[N]; // p^i

ULL get(int l, int r) {
    return h[r] - h[l - 1] * p[ r - l + 1];
}

int main() {
    scanf("%d%d%s", &n, &m, str + 1);

    p[0] = 1;

    for (int i = 1; i <= n; i ++ ) {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i];
    }

    while (m -- ) {
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if (get(l1, r1) == get(l2, r2)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}