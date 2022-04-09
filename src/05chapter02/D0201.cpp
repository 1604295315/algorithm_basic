#include <iostream>

using namespace std;

const int N = 100010;

// ******************** 栈
void stack(int x) {
    int stk[N], tt;
    // 初始化
    tt  = 0;
    // 插入
    stk[++tt] = x;
    // 删除
    tt --;
    // 判空
    // tt > 0 ? not empty : empty;
    // stk[tt];
}

// ******************** 队列
void queue(int x) {
    // 在tt队尾插入元素
    // 在hh对头弹出元素
    // front push
    int q[N], hh, tt;
    // 初始化
    hh = tt = -1;
    // 插入
    q[++tt] = x;
    // 弹出
    q[hh ++];
    // 判空
    if (hh < tt);// not empty
    // 取出队头元素
    q[hh];
    q[tt];
}

// STL Warning
// 记忆力 毅力 自制力 
// 限时 --> 空间换时间
// 背出 与 推出

int main() {
    return 0;
}