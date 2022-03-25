// 790. 数的三次方根
// 二分查找 浮点数

#include <iostream>

using namespace std;

int main() {
    double x = 0;
    scanf("%lf", & x);
    double l = -10000, r = 10000;
    while (r - l > 1e-8) {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= x)
            r = mid;
        else
            l = mid;
    }

    printf("%lf\n", l);
    return 0;
}