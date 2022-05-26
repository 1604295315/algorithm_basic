// AcWing 840. 模拟散列表
// 有点像 区间离散化
// 离散化 稀疏 -> 紧密 (极其特殊的hash方式) (把连续的搜索空间变小)
// 哈希 高纬度 -> 低纬度
// 维护一个集合, 支持如下几种操作 :
// I x, 插入一个数 x; 
// Q x, 询问数 x 是否在集合中出现过; 
// 现在要进行 N 次操作, 对于每个询问操作输出对应的结果. 
// 输入格式
// 第一行包含整数 N, 表示操作数量. 
// 接下来 N 行, 每行包含一个操作指令, 操作指令为 I x, Q x 中的一种. 
// 输出格式
// 对于每个询问指令 Q x, 输出一个询问结果，如果 x 在集合中出现过, 则输出 Yes, 否则输出 No. 
// 每个结果占一行. 
// 数据范围 1 ≤ N ≤ 10^5 ; −10^9 ≤ x ≤ 10^9
#include <iostream>
#include <cstring>
using namespace std;

const int N = 100003;
// 大于 1e5的第一个质数 素数 素数筛
// 取一个最接近N的质数 冲突的概率最小
// 期望算法 ~ O(1)
// 因为链子 是比较短 且 常数 长 的

int h[N], e[N], ne[N], idx;

void insert(int x) {
    int k = (x % N + N) % N;
    // 负数模上N -10 % 3 = 2 、 C++ = -1
    // 漂亮 头插法
    e[idx] = x, ne[idx] = h[k], h[k] = idx ++;
}

bool find(int x) {
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i]) {
        if (e[i] == x)
            return true;
    }
    return false;
}
int main() {
    int n;
    scanf("%d", &n);
    memset(h, -1, sizeof(h));
    while (n --) {
        char op[2]; 
        // 字符数组用来表示字符串会以\0结尾   
        // 读入字符串会过滤空格，很方便；直接读入字符不会过滤空格（也就是说有可能直接读入到了一个空格），还得在自己搞搞，还容易错
        int x;
        scanf("%s%d", op, &x);
        if (*op == 'I') insert(x);
        else {
            if (find(x)) puts("Yes");
            else puts("No");
        }
    }
}
// h(x) -10^9 ≤ x ≤ 10^9 ---> 1 ≤ N ≤ 10^5 ; 
// x % 10^5 (0,10^5)
// 冲突解决 : 开放寻址法 -> 线性探测再散列法
//                      -> 平方探测法
//                      -> 再散列法
//                      -> 伪随机序列法
//           拉链法 (哈希桶)
