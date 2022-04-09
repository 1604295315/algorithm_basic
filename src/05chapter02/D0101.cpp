// AcWing 826.单链表

#include <iostream>

using namespace std;

const int N = 100010;

// head 表示头结点的下表
// e[i] 表示结点i的值
// ne[i] 表示结点i的next指针是多少
int head, e[N], ne[N];
// 存储当前用到了哪个点, 指针
int idx;
// idx表示新开结点的地址

void init() {
    head = -1;
    idx = 0;
}

// 将x插到头结点
// 不带头结点的头插法
void add_to_head(int x) {
    e[idx] = x, ne[idx] = head, head = idx ++ ;
}

// 将x插到下标为k的点的后面
void add(int k, int x) {
    e[idx] = x;
    ne[idx] = ne[k]; 
    ne[k] = idx;
    idx ++; 
}

// 将下标是k的点后面的点删掉
void remove(int k) {
    ne[k] = ne[ne[k]];
}

void print() {
    for (int i = head; i != -1; i = ne[i])
        printf("%d ", e[i]);
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    init();

    while (n --) {
        char op;
        int k, x;
        cin >> op;
        switch (op) {
            case 'H' : 
            cin >> x; add_to_head(x); break;
            case 'D' : 
            cin >> k;
            if (!k) head = ne[head];
            remove(k - 1); break;
            case 'I' : 
            cin >> k >> x; add(k - 1, x); break;
            default : break;
        }
    }
    print();
    
    return 0;
}