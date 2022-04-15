#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, M = 1000010;

int n, m;
char p[N], s[M];

int ne[N];

int main() {
    scanf("%d%s", &n, p);
    scanf("%d%s", &m, s);
    
    for (int i = 2, j = 0; i <= n; i ++) {
        while (j && p[i] != p[j + 1])
            j = ne[j];
        if (p[i] == p[j + 1]) j ++;
        ne[i] = j;
    }

    for (int i = 1, j = 0; i <= m; i ++) {
        while (j && s[i] != p[j + 1]) 
            j = ne[j];
        if (s[i] == p[j + 1]) j ++;
        if (j == n) printf("%d ", i - n);
    }
    return 0;
}