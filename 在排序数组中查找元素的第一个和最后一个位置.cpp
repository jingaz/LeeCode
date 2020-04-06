#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int binsearch(vector<int> nums, int left, int right, int target) {
    int ans = -1;
    while (left <= right) {
        if (target == nums[left])
            return left;
        if (target == nums[right])
            return right;
        int mid = (left + right) / 2;
        if (target == nums[mid])
            return mid;
        if (target > nums[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}
int left_search(vector<int> nums, int left, int right, int target) {
    int mid = (left + right) / 2;
    while (left < right && mid <= right) {
        mid = (left + right) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}
int right_search(vector<int> nums, int left, int right, int target) {
    int mid = (left + right + 1) / 2;
    while (left < right && mid >= left) {
        mid = (left + right + 1) / 2;
        if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid;
        }
    }
    return right;
}
vector<int> searchRange(vector<int> &nums, int target) {
    if (nums.empty()) {
        return vector<int>{-1, -1};
    }
    int left = 0, right = nums.size() - 1;
    int mid = binsearch(nums, left, right, target);
    if (mid == -1) {
        return vector<int>{-1, -1};
    }
    // 确定左边界
    left = left_search(nums, 0, mid, target);
    // 确定右边界
    right = right_search(nums, mid, nums.size() - 1, target);
    return vector<int>{left, right};
}

struct testdata {
    vector<int> num_array;
    int target;
};

int main() {
    vector<testdata> data = {
        {{5, 7, 7, 8, 8, 10}, 8},
        {{5, 5, 5, 8, 8, 10, 2}, 6},
    };
    for (testdata i : data) {
        vector<int> ret = searchRange(i.num_array, i.target);
        cout << "[ " << ret[0] << ",  " << ret[1] << " ]" << endl;
    }
}