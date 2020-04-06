#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int searchInsert(vector<int> &nums, int target) {
    int left=0,right=nums.size()-1;
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
    nums.insert(nums.begin() + left, target);
    return left;
}
struct testdata {
    vector<int> num_array;
    int target;
};

int main() {
    vector<testdata> data = {
        {{1, 3, 5, 6}, 5},
        {{1, 3, 5, 6}, 2},
        {{1, 3, 5, 6}, 7},
        {{1, 3, 5, 6}, 0},
    };
    for (testdata i : data) {
        cout << searchInsert(i.num_array, i.target) << endl;
    }
}