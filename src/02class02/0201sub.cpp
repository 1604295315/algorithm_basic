#include <iostream>
#include <vector>
using namespace std;

bool cmp(vector<int> &A, vector<int> &B) {
    long int a = 0, b = 0;
    for (int i = 0; i < A.size(); i ++) {
        a += A[i];
        a *= 10;
    }
    a /= 10;
    
    for (int i = 0; i < B.size(); i ++) {
        b += B[i];
        b *= 10;
    }
    b /= 10;

    if (a >= b ) 
        return true;
    else
        return false;

}
vector<int> sub(vector<int> &A, vector<int> &B) {
    
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() ; i ++) {
        t = A[i]+t;
        if (i < B.size()) t -= B[i];
        else t -= 0;
        if(t > 0) {
            C.push_back(t);
            t = 0;
        }
        else {
            C.push_back(t + 10);
            t = -1;
        }
    }
    return C;
}

int main () {
    vector<int> A, B;
    string a,b;

    cin >> a >> b;

    for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i --) B.push_back(b[i] - '0');
    vector<int> C;
    if (cmp(A,B))
    {
        C = sub(A, B);
    }
    else
    {
        printf("-");
        C = sub(B,A);
    }

    for (int i = C.size() - 1; i >= 0; i--) printf("%d",C[i]);

    return 0;
}
