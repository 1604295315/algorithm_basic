// 离散化
// 802. 区间和
// 无限长的数轴 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 300010;
// const int N = 1e9 + 10;
// const int N1 = 1e5 + 10;

// 2*10^9 3*10^5
// 值域大 但稀疏

int n , m;
int a[N], s[N];

vector<int> alls;
vector<PII> adds, query;

int find(int x) {
    int l = 0, r = alls.size() - 1;
    while(l < r)
    {
        int mid = r + l >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;
}

vector<int>::iterator unique(vector<int> &a) {
    int j = 0;
    for (int i = 0; i < a.size(); i ++)
        if (!i || a[i] != a[i - 1])
            a[j ++] = a[i];
    // a[0] ~ a[j - 1] 所有 a 中不同(重复)的数
    return a.begin() + j;
}

int main() {
    cin >> n >> m;
    while (n --){ 
        int x, c;
        cin >> x >> c;
        adds.push_back({x, c});
        alls.push_back(x);
    }

    while (m --) {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }

    // 去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end())\
        , alls.end());

    // 处理插入
    for (auto item: adds) {
        int  x = find(item.first);
        a[x] += item.second;
    }

    // 预处理前缀和
    for (int i = 1; i <= alls.size(); i ++) {
        s[i] = s[i - 1] + a[i];
    }
    
    // 处理询问
    for (auto item : query) {
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}

