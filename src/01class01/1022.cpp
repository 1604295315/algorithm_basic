//浮点数二分
//输入一个正浮点数, 求它的平方根
#include <iostream>

using namespace std;

int main()
{
    double x = 0;
    // scanf("%lf", &x);
    cin >> x;
    double l = 0, r = x;
    // while (r - l > 1e-8)
    if (r < 1)
        r = 1;
    for (int i = 0; i < 100; i++)
    {//4 -6 5 -7 6 -8 经验值
        double mid = (l + r) / 2.0;
        if((mid * mid) >= x)
            r = mid;
        else    
            l = mid;
    }
    cout << "l = :"<< l << endl;
    printf("%lf\n", l);
    return 0;
}