#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<int>> FourSum(vector<int> &nums, int target) {
    vector<vector<int>> ret;
    if (nums.size() < 4) {
        return ret;
    }

    sort(nums.begin(), nums.end());

    int arr_min = 0, arr_max = 0;
    for (int i = 0; i < 4; i++) {
        arr_min += nums[i];
        arr_max += nums[nums.size() - 1 - i];
    }
    if (target < arr_min || target > arr_max) {
        return ret;
    }

    const int arr_size = nums.size();
    int A, B, C, D;
    int i = 0, j = 1, k = 2;
    do {
        A = nums[i];
        B = nums[j];
        C = nums[k];
        D = target - A - B - C;
        if (binary_search(begin(nums) + k + 1, end(nums), D)) {
            ret.push_back(vector<int>{A, B, C, D});
        }
        while (k <= arr_size - 2 && nums[++k] == C) {
        }
        if (k <= arr_size - 2) {
            continue;
        }
        while (j <= arr_size - 3 && nums[++j] == B) {
        }
        if (j <= arr_size - 3) {
            k = j + 1;
            continue;
        }
        while (i <= arr_size - 4 && nums[++i] == A) {
        }
        if (i <= arr_size - 4) {
            j = i + 1;
            k = j + 1;
        } else {
            break;
        }
    } while (i <= arr_size - 4);

    return ret;
}

int main() {

    vector<vector<int>> testdata = {
        {1, 0, -1, 0, -2, 2, 0},
    };
    for (auto it : testdata) {

        // it.back()作为target 方便测试
        int target = it.back();
        it.pop_back();

        for (auto ans : FourSum(it, target)) {
            cout << "[ ";
            for (int i : ans) {
                cout << i << ", ";
            }
            cout << "\b\b ]  ";
        };
        cout << endl;
    }
}