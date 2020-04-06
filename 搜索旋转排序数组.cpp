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

int search(vector<int> &nums, int target) {
    int ans = -1;
    if (nums.size() <= 3) {
        for (int i = 0; i < nums.size(); i++) {
            ans = nums[i] == target ? i : ans;
        }
        return ans;
    }

    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        if (target == nums[left])
            return left;
        if (target == nums[right])
            return right;

        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            return mid;
        }

        // mid在右边部分
        if (nums[mid] < nums[left]) {
            if (target > nums[right]||target<nums[mid]) {
                right = mid - 1;
            } else {
                if(target>nums[mid]){
                  return binsearch(nums, mid + 1, right - 1, target);
                }
            }
        }
        // mid在左边部分
        else {
            if (target > nums[mid] || target < nums[left]) {
                left = mid + 1;
            } else {
                return binsearch(nums, left + 1, mid - 1, target);
            }
        }
    }
    return ans;
}

struct testdata {
    vector<int> num_array;
    int target;
};

int main() {
    vector<testdata> data = {
        {{4, 5, 6, 7, 0, 1, 2}, 0},
        {{4, 5, 6, 7, 0, 1, 2}, 3},
        {{5, 1, 2, 3, 4}, 1},
    };
    for (testdata i : data) {
        cout << search(i.num_array, i.target) << endl;
    }
}