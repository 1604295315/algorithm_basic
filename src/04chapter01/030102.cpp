//Acwing. 799
// 给定一个长度为n的整数序列, 请找出最长的不包含重复数字的连续子序列, 输出它的长度. 
// eg : `1 2 2 3 5`
// eg : `9 3 6 9 5 10 1 2 3 9`
// C++11新特性里有四个无序容器, 内部实现了哈希表
#include <iostream>

using namespace std;

const int N = 100010;

int n , q[N], s[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> q[i];
    // i: j往左最远能到什么地方.
    int res = -1;
    for (int i = 0, j = 0; i < n; i ++) {
        s[q[i]] ++;
        // j <= i && 
        while (s[q[i]] > 1) s[q[j++]] -- ;
        res = max(res, i - j + 1);
    }
    cout << res << endl;
    return 0;
}
// 次暴力但会超时
// int check(int j, int i)
// {
//     int flag = 0;
//     for (int k = j; k <= i; k ++)
//     {
//         s[q[k]]++;
//     }
//     for (int k = j; k <= i; k ++)
//     {
//         if(s[q[k]] > 1){
//             flag = 1;
//         }
//     }
//     if(!!flag)
//         return 0;
//     return 1;
// }
// 足够暴力但会超时
// int check(int j, int i) {
//     for (int k = j; k <= i; k ++)
//     {
//         for (int l = j + 1; l <= i; l ++)

//         if (l != k && q[l] == q[k]) {
//             return 0;
//         }
//     }
//     return 1;
// } 
/* 暴力做法 */ 
// int main() {
//     cin >> n;
//     for (int i = 0; i < n; i ++) cin >> q[i];
//     int res = 0;
//     for (int i = 0; i < n; i ++) 
//         for (int j = 0; j <= i; j ++)
//             if (check(j,i))
//             {
//                 res = max(res, i - j + 1);
//             }
//     printf("%d\n",res);
//     return 0;
// }