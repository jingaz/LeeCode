#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int> &nums) {
    if (nums.size() == 1) {
        return nums.back();
    }
    int max_value = nums.front();
    int tmp_max = max_value;
    for (int index = 1; index < nums.size(); index++) {
        int i = nums[index];
        if (i >= 0) {
            if (tmp_max >= 0) {
                tmp_max += i;
                max_value = max(max_value, tmp_max);
            } else {
                tmp_max = i;
                max_value = max(max_value, tmp_max);
            }

        } else {
            if (tmp_max >= 0) {
                tmp_max += i;
            } else {
                tmp_max = i;
                max_value = max(max_value, tmp_max);
            }
        }
    }
    return max_value;
}

int main() {
    vector<vector<int>> testdata = {{-2, 1, -3, 4, -1, 2, 1, -5, 4}, {1}};
    for (auto it : testdata) {
        cout << maxSubArray(it) << endl;
    }
}