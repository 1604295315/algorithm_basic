// 宽搜, 可以搜到最短路 一圈一圈搜索
// 八数码 带权重
// 求一个最小步数
// 最短路 用 bfs
// 1. 状态表示复杂
//    直接用字符串来表示
// 2. 距离数组的下表如何表示 如何记录每个状态的距离
// BFS: 队列 dist
// 3. 状态的转换 如何判断 转换
//    恢复3x3 x的上下左右 移动 恢复成字符串
// dist
// C++ hashmap unordered_map<string> dist
// python dict
// java 字典
#include <iostream>
#include <algorithm>
#include <unordered_map> //hash table store the dist
#include <queue> // bfs queue

using namespace std;



const int N = 15;


// 搜索八数码最小步数
int bfs(string start) {
    string end = "12345678x";
    
    queue<string> q;
    unordered_map<string, int> d; // 距离数组

    q.push(start);
    d[start] = 0;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    while (q.size()) {
        auto t = q.front();
        q.pop();
        
        int distance = d[t];
        if(t == end) return distance;

        // 状态的转移
        int k = t.find('x');
        int x = k/3, y = k%3;

        for (int i = 0; i < 4; i ++) {
            int a = x + dx[i];
            int b = y + dy[i];
            if (a >=0 && a < 3 && b >= 0 && b < 3) { // 如果 a b 没有出界
                swap(t[k],t[a*3+b]);
                if (!d.count(t)) {
                    d[t] = distance + 1;
                    q.push(t);
                }
                swap(t[k], t[a*3+b]);
            }
        }

    }
    return -1;
}

int main() {
    string start;
    for (int i = 0; i < 9; i ++) {
        char c;
        cin >> c;
        start += c;
    }   
    cout << bfs(start) << endl;
    return 0;
}

