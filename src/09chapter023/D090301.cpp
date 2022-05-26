// 常用stl 模板 用法
#include <iostream>
#include <vector>
#include <cstring>
#include <queue> // 队列 优先队列
#include <stack>
#include <deque>
#include <set> // set multiset
#include <map> // map multimap
#include <unordered_map>
#include <bitset>

using namespace std;

int main() {
    vector<int> a;
    vector<int> b(10, -3);
    vector<int> c[10];
    for (auto x : b) cout << x << endl;
    // size empty 所有容器都有
    a.size(); // 返回个数 O(1)
    a.empty(); // 判断 是否为空 O(1)
    a.clear(); // 清空 并不是所有的容器都有
    // vector 变长数组 大小为倍增 a.size() * 2;
    // 系统为某一程序分配空间时所需时间 与空间大小无关 只与申请次数有关
    // 长度为 n 申请次数 logn
    a.front(); // 返回第一个数
    a.back(); // 返回最后一个数
    a.push_back(1); 
    a.pop_back(); 
    a.begin(); // 有迭代器
    a.end();
    // []; 支持随即寻址
    // 迭代器遍历
    for (vector<int>::iterator i = a.begin(); i != a.end(); i ++) 
        cout << *i << ' '; // *i解引用
    // 范围遍历 C11 新语法
    for (auto x : b) cout << x << endl;
    // 支持比较运算
    vector<int> c(4, 3), d(3, 4);
    // 按字典序来比 重载了运算符
    if (a < b) puts("a < b");
    /*********************/
    // pair map的亲戚
    pair<int, string> p; //存储一个二元组 前后两个变量类型可以任意
    p.first, p.second; // 取第一第二分元素
    // 支持比较运算 按字典序 first 为第一关键字 second 为第二关键字
    auto c = make_pair(10, "abc");
    p = {20,"abc"};
    pair<int, pair<int,int>> ee;

    /*********************/
    // string
    int n = 10;
    string s;
    s.size();
    s.length();
    s.empty();
    s.clear();
    s += "dsf";
    s += '\n';
    s.substr(1, n); // n为字串长度 若太大,则到主串结尾止
    printf("%s\n", s.c_str()); // printf 无法直接输出string

    /*********************/
    // queue 队列
    queue<int> q;
    // size(); empty(); 无 clear();
    q.push(10);
    q.front();
    q.back(); 
    q.pop(); // 弹出队尾元素
    q = queue<int>(); // 重新构造一个队列 相当于清空了

    /*********************/
    // 堆 priority_queue
    // push pop top 无 celar
    // 默认是大根堆
    priority_queue<int> heap;
    // 定义一个小根堆
    // 1. 直接插入负数 (黑科技)
    // 2. 定义成小根堆
    priority_queue<int, vector<int>, greater<int>> heap_min;

    /*********************/
    // 栈 stack
    // push pop top 无 clear
    // empty size
    stack<int> stack_i;

    /*********************/
    // deque 双端队列 加强版的vector
    // empty size clear
    // front back push_back pop_back push_front pop_front
    // []
    // begin end 迭代器
    // 速度相对比较慢

    /*********************/
    // set multiset
    // set 不可有重复元素
    // multiset 可以有重复元素 
    // size empty clear
    // begin end ++ -- 返回前驱 和 后继 O(logn)
    // insert() 插入一个数 logn
    // find() 查找一个数 不存在 返回end 迭代器
    // count() 返回某一个数的个数
    // erase()
    // 1. 输入时一个数 -> 删除所有x O(k + logn)
    // 2. 输入时一个迭代器 -> 删除这个迭代器
    // lower_bound() / upper_bound()
    // 单调栈
    // 最小上界 最大下界
    // 1. 返回>=x的最小的迭代器
    // 2. 返回> x的最小的迭代器


    /*********************/
    // map multimap 
    // inser 插入的是一个pair
    // erase pair 或者 迭代器
    // find()
    // [] 像数组一样用 时间复杂度 O(logn) 
    map<string, int> m;
    m["yxc"] = 1;
    cout << m["abc"] << endl;
    // lower_bound() / upper_bound()

    /*********************/
    // unordered_set, unordered_map, unordered_multiset, unordered_multimap
    // 和上面的类似 但 增删改查 时间复杂度是O(1)
    // 缺点 : 不支持 lower_bound() / upper_bound() 不支持迭代器的++ -- 
    // 哈希表 实现的 
    unordered_multimap<string, int> hashtable;

    /*********************/
    // bitset, 压位
    // 长度为1024的bool数组 2^10
    // c++ bool 1 Byte
    bitset<10000> S; // 长度为10000的bitset
    // ~, &, |, ^
    // >> , <<
    // ==, != 
    // []
    // count() 返回有多少个1
    // any(); 判断是否至少有一个1
    // none(); 判断是否全为 0
    // set() 所有位置 1
    // set(k, v); 第k位 置 v
    // reset(); 所有位 置 0
    // flip(); 所有位 取反
    // flip(k); 第k位 取反
    return 0;
}