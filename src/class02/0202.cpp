/*
输入一个长度为 n 的整数序列。
接下来再输入 m 个询问，每个询问输入一对 l,r。
对于每个询问，输出原序列中从第 l 个数到第 r 个数的和。
*/

#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int main() {
    int n,m;
    int q[N];
    int s[N];

    cin >> n >> m;
    
    for (int i = 0; i < n; i ++)
        scanf("%d",q+i);

    // 前缀和初始化
    s[0] = 0;

    for (int i = 1; i < n; i ++)
        s[i] = s[i - 1] + q[i];

    int l = 0, r = 0;
    while(m --){
        scanf("%d%d", &l, &r);
        printf("%d\n", s[l] - s[r - 1]);
    }
}
