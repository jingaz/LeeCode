#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    while (n) {
        if (m > 0) {
            if (nums1[m - 1] > nums2[n - 1]) {
                nums1[m + n - 1] = nums1[m - 1];
                m--;
            }
            else{
                nums1[m + n - 1] = nums2[n - 1];
                n--;
            }
        } else {
            nums1[n - 1] = nums2[n - 1];
            n--;
        }
    }
}

void print_ret(vector<int> ret) {
    cout << "[  ";
    for (auto i : ret) {
        cout << i << ", ";
    }
    cout << "\b\b  ]" << endl;
}
struct testdata {
    vector<int> nums1;
    int m;
    vector<int> nums2;
    int n;
};
int main() {
    vector<testdata> data = {
        {{1, 2, 3, 0, 0, 0}, 3, {2, 5, 6}, 3},
        {{}, 0, {}, 0},
        {{4,0}, 1, {3}, 1},
    };
    for (auto &it : data) {
      merge(it.nums1, it.m, it.nums2, it.n);
      print_ret(it.nums1);
    }
}