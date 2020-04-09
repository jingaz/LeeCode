#include <iostream>
#include <vector>

using namespace std;

double myPow(double x, int n) {
    double tmp_x = x;
    if (n == 0)
        return 1;
    if (n == 1) {
        return x;
    }
    if (x == 1) {
        return x;
    }
    if (n > 0) {
        unsigned int i = 1;
        while (i * 2 <= n) {
            x *= x;
            i *= 2;
        }
        return x * myPow(tmp_x, n - i);
    } else if (n > INT32_MIN) {
        return 1 / myPow(x, -n);
    } else {
        int last = INT32_MIN - n+1;
        return 1 / (myPow(x, INT32_MAX) * myPow(x, last));
    }
}
struct testdata {
    double x;
    int n;
};
int main() {
    vector<testdata> data = {
        {-1.00000, -2147483648}, {0.00001, 2147483647}, {2.00000, -2147483648}};
    for (auto it : data) {
        cout << myPow(it.x, it.n) << endl;
    }
}