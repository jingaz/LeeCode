#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int mySqrt(int x) {
    // return sqrt(x);
    if (x == 0)
        return 0;
    int left = 1;
    int right = x;
    while (left <= right) {
        if (x / left >= left && x / (left + 1) <  1 + left) {
            return left;
        }
        if (x / right >= right && x / (right + 1) <  1 + right) {
            return right;
        }
        int mid = (left + right) / 2;
        if (x/mid >= mid && x / (mid + 1) < 1 + mid) {
            return mid;
        } else if (x / mid >= mid) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0;
}

int main() {
    vector<int> testdata = {4};
    for (int i : testdata)
        cout << mySqrt(i) << endl;
}