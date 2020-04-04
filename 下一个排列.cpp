#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void nextPermutation(vector<int> &nums) {
    if (nums.size() < 2) {
        return;
    }
    int i;
    for (i = 0; i < nums.size() - 1; i++) {
        if (nums[i] < nums[i + 1]) {
            break;
        }
    }
    // 降序变升序
    if (i == nums.size() - 1 && nums[i - 1] >= nums[i]) {
        return reverse(nums.begin(), nums.end());
    }
    for (vector<int>::reverse_iterator r = nums.rbegin(); r != nums.rend();
         r++) {
        if (*(r + 1) < *r) {
            sort(nums.rbegin(), r+1, [](int a, int b) { return a > b; });
            vector<int>::reverse_iterator r_tmp = r;

            while (*r_tmp <= *(r + 1)) {
                r_tmp--;
            }
            swap(*(r+1), *r_tmp);
            return;
        }
    }
}

void print_num(vector<int> nums) {
    for (int i : nums) {
        cout << i << ", ";
    }
    cout << "\b\b";
}

int main() {
    vector<vector<int>> num_array = {
        {1, 3, 2}, {3, 2, 1}, {1, 5, 1}, {9, 1, 7, 5, 8, 7, 6, 2}};
    for (auto &it : num_array) {
        print_num(it);
        cout << " -> ";
        nextPermutation(it);
        print_num(it);
        cout << endl;
    }
}
