#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {

    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }

    int m = nums1.size(), n = nums2.size();
    int imin = 0, imax = m, halflen = (m + n + 1) / 2;
    while (imin <= imax) {
        int i = (imin + imax) / 2;
        int j = halflen - i;
        if (i < imax && nums2[j - 1] > nums1[i]) {
            imin = i + 1; //这个情况表示还能向右移动
        } else if (i > imin && nums1[i - 1] > nums2[j]) {
            imax = i - 1; //这个情况表示还能向左移动
        } else {          //不能移动了，表示找到位置了
            int max_left = 0;
            if (i == 0) {
                max_left = nums2[j - 1];
            } else if (j == 0) {
                max_left = nums1[i - 1];
            } else {
                max_left = max(nums1[i - 1], nums2[j - 1]);
            }
            if ((m + n) % 2 == 1) {
                return max_left;
            }

            int min_right = 0;
            if (i == m) {
                min_right = nums2[j];
            } else if (j == n) {
                min_right = nums1[i];
            } else {
                min_right = min(nums1[i], nums2[j]);
            }
            return (max_left + min_right) / 2.0;
        }
    }
    return 0.0;
}
struct testdata {
    vector<int> nums1;
    vector<int> nums2;
};

int main() {
    vector<testdata> alldata = {{{1, 3}, {2}}, {{1, 2}, {3, 4}}};
    for (auto data : alldata) {
        cout << findMedianSortedArrays(data.nums1, data.nums2) << endl;
    }
}