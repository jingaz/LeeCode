#include <iostream>
#include <vector>
using namespace std;

int divide(int dividend, int divisor) {
    //边界情况
    if (dividend == divisor)
        return 1;
    if (divisor == INT32_MIN)
        return 0;

    bool flag = dividend == INT32_MIN;
    if (flag)
        dividend += abs(divisor);

    bool same = dividend >= 0 == divisor >= 0; //是否同正负
    dividend = abs(dividend);                  //全部转化为正数处理
    divisor = abs(divisor);

    int res = 0;
    for (int i = 31; i >= 0; i--) {
        int temp = dividend >> i;
        res = (res << 1) + (temp >= divisor);
        if (temp >= divisor)
            dividend -= divisor << i;
    }
    if (flag)
        return same ? (res != INT32_MAX ? res + 1 : res) : -res - 1;
    return same ? res : -res;
}

int main() {
    vector<vector<int>> testdata = {
        {-1, -1}, {-2147483648, -1}, {7, -3}, {-1, 1}, {2147483647, 3}};
    for (auto it : testdata) {
        cout << divide(it[0], it[1]) << endl;
    }
}