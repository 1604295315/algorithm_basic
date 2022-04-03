// 区间合并
// 两个有交集的区间, 合并成为一个
// 排序 + 贪心
// 1. 按区间的左端点排序
// 2. 扫描整个区间 维护一个当前的区间 遇断 入栈 维护下一个区间
// 2.1. 内部有交集 端点交集 断交
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

int n;
vector<PII> segs;

void merge(vector<PII> & segs) {
    vector<PII> res;

    sort(segs.begin(), segs.end());

    int st = -2e9, ed = -2e9;
    for (auto seg : segs) {
        if (ed < seg.first)
        {
            if (st != -2e9) res.push_back({st, ed});
            st = seg.first, ed = seg.second;
        }
        else ed = max(ed, seg.second);
    }
    if (st != -2e9) res.push_back({st, ed});
    segs = res;
}

int main() {
    cin >> n;
    while(n --) {
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }

    merge(segs);
    cout << segs.size() << endl;

    return 0;
}