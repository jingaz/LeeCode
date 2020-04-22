#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }
    int cnt = 0;
    int cur = nums.front();
    int index = 0;
    while (nums.size() > 2 && index < nums.size()) {
        if (nums[index] == cur) {
            cnt++;
            if (cnt > 2) {
                nums.erase(nums.begin() + index);
            }else{
              index++;
            }
        } else {
            cnt = 1;
            cur = nums[index];
            index++;
        }
    }
    return nums.size();
}

void print_ret(vector<int> ret) {
    cout << "ret.size() = " << ret.size() << " [  ";
    for (auto i : ret) {
        cout << i << ", ";
    }
    cout << "\b\b  ]" << endl;
}

int main() {
    vector<vector<int>> testdata = {
        {1, 1, 1, 2, 2, 3,3,3,3,3,3,6,6,6,7,8,9},
        {0, 0, 1, 1, 1, 1, 2, 3, 3},
        {},
    };
    for (auto &it : testdata) {
        removeDuplicates(it);
        print_ret(it);
    }
}