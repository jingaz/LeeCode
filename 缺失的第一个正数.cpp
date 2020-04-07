#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int firstMissingPositive(vector<int> &nums) {
    int left = 1;
    int right = nums.size() + 1;
    unordered_set<int> mid_nums;
    // 结果在left~right之间（包括两端点）
    for (int &i : nums) {
        if (left == right) {
            return left;
        }
        if (i < left || i >= right) {
            right--;
        } else if (i == left) {
            left++;
            while (mid_nums.count(left)) {
                left++;
            }
        }
        // left<i<right
        else {
            mid_nums.insert(i);
        }
    }
    return left;
}

int main() {
    vector<vector<int>> testdata = {
        {1, 2, 0, -1, -2, 5, 7, 9, 88, 56, 34, 23, 21, 4, 65, 8, 3},
        {3, 4, -1, 1, 2},
        {7, 8, 9, 11, 12},
    };
    for (auto it : testdata) {
        cout << firstMissingPositive(it) << endl;
    }
}