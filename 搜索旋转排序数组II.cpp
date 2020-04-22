#include <iostream>
#include <vector>
using namespace std;
int binsearch(vector<int> nums, int left, int right, int target) {
    bool ans = false;
    while (left <= right) {
        if (target == nums[left])
            return true;
        if (target == nums[right])
            return true;
        int mid = (left + right) / 2;
        if (target == nums[mid])
            return true;
        if (target > nums[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}
bool search(vector<int> &nums, int target) {
    bool ans = false;
    if (nums.size() <= 3) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target)
                return true;
        }
    }

    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        if (target == nums[left])
            return true;
        if (target == nums[right])
            return true;

        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            return true;
        }

        // mid在右边部分
        if (nums[mid] < nums[left]) {
            if (target > nums[right] || target < nums[mid]) {
                right = mid - 1;
            } else {
                return binsearch(nums, mid + 1, right - 1, target);
            }
        }
        // mid在左边部分
        else if (nums[mid] > nums[right]) {
            if (target > nums[mid] || target < nums[left]) {
                left = mid + 1;
            } else {
                return binsearch(nums, left + 1, mid - 1, target);
            }
        } else {
            right--;
            left++;
        }
    }
    return ans;
}
void print_ret(vector<int> ret) {
    cout << "  [";
    for (auto i : ret) {
        cout << i << ", ";
    }
    cout << "\b\b]" << endl;
}
struct testdata {
    vector<int> num_array;
    int target;
};
int main() {
    vector<testdata> data = {{{2, 5, 6, 0, 0, 1, 2}, 0},
                             {{2, 5, 6, 0, 0, 1, 2}, 3},
                             {{1, 1, 1, 3, 1}, 3},
                             {{1, 3, 1, 1, 1}, 3}};
    for (testdata i : data) {
        cout << boolalpha << search(i.num_array, i.target) << endl;
    }
}