//整数二分 O(logn)
//acwing 789 数的范围
#include <iostream>

using namespace std;

const int N = 1000010;

int n, m;
int q[N];

int main(int argc, const char** argv) 
{
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i ++)
        scanf("%d", &q[i]);

    while(m --)
    {
        int x;
        scanf("%d", &x);

        int l = 0, r = n - 1;
        while(l < r)
        {
            int mid = l + r >> 1;
            if (q[mid ] >= x)
                r = mid;
            else
                l = mid + 1;
        }
        //找到了第一个大于等于x的数 边界
        //若该数 > x 则说明不存在该数
        if (q[l] != x)
            cout << "-1 -1" << endl;
        else
        {
            cout << l << ' ';
            int l = 0, r = n-1;
            while( l < r)
            {
                int mid = l + r + 1 >> 1;
                if( q[mid] <= x)
                    l = mid;
                else
                    r = mid - 1;
            }
            cout << l << endl;
        }
    }
    return 0;
}