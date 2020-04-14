#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int C(int n, int k) {
    long long s = 1;
    int x = 1;
    if (k > n - k)
        k = n - k;
    for (int i = n; i > n - k; i--) {
        s *= i;
        s /= x;
        x++;
    }
    return (int)s;
}

int uniquePaths(int m, int n) {
    // 计算 C(m+n-2, m-1)排列组合公式
    return C(m+n-2, m-1);
}

struct testdata {
    int m;
    int n;
};
int main() {
    vector<testdata> data = {
        {10, 10},
        {6, 8},
        {2, 1},
    };
    for (auto it : data) {
        cout << uniquePaths(it.m, it.n) << endl;
    }
}