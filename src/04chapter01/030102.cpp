//Acwing. 799
// 给定一个长度为n的整数序列, 请找出最长的不包含重复数字的连续子序列, 输出它的长度. 
// eg : `1 2 2 3 5`
#include <iostream>

using namespace std;

const int N = 100010;
int n , q[N];
int check(int x1, int x2) {
    for (int i = x1; i < n; i ++)
        if (q[x1] == q[i])
            return 1;
    return 0;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> q[i];

    int res = -1;
    for (int i = 0, j = 0; i < n; i ++) {
        while (j < n && check(i,j)) j ++;
        res = max(res, j - i + 1);
        if (j == n) res = n;
        i = (j ++) + 1;
    }
    cout << res << endl;
    return 0;
}

/* 暴力做法 */
// int main() {
//     cin >> n;
//     for (int i = 0; i < n; i ++) cin >> q[i];
//     for (int i = 0; i < n; i ++) 
//         for (int j = 0; j < n; j ++)
//             if (check(i,j))
//             {
//                 res = max(res, j - i + 1)
//             }
//     return 0;
// }