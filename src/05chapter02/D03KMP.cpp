// 字符串模式匹配 KMP
#include <iostream>

const int N = 100010, M = 1000010;

int n, m;
char p[N], s[M];
int ne[N];

int main() {
    scanf("%d%s", &n, p + 1);
    scanf("%d%s", &m, s + 1);

    // 求ne的过程
    for (int i = 2, j = 0; i <= n; i ++) {
        while (j && p[i] != p[j + 1]) {
            j = ne[j];
        }
        if (p[i] == p[j + 1]) j ++;
        ne[i] = j;
    }

    // KMP 匹配过程
    for (int i = 1, j = 0; i <= m; i ++) {
        
        while (j && s[i] != p[j + 1])
            j = ne[j]; // 退一步看看能不能继续往前走
        if (s[i] == p[j + 1])
            j ++;
        if (j == n)
        {
            // 匹配成功
            printf("%d ", i - n);
            j = ne[j];
            // 向后移动继续匹配
        }
    }
    return 0;
}
// next i 表示 以i为终点的后缀 和 从1开始的前缀相等
// p[1, j] = p[i-j+1, i];
// 最长公共前后缀
// 长度为i的后缀的最长前缀长度
// 最长的与前缀相等的后缀的长度 非平凡

// 比较指针j回溯
// next数组
// nextval 数组

/*
// 模式串s 主串
// 模板串p 模式串
// s = ""
// p = "abababab"
// 1 2 3 4 5 6 7 8
// 0 0 1 2 3 4 5 6
*/

