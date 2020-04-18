#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int> &nums) {
    int length = nums.size();
    for (int i = 0; i < length;) {
        if (nums[i] == 2) {
            nums.erase(nums.begin() + i);
            nums.push_back(2);
            length--;
        } else if (nums[i] == 0) {
            nums.erase(nums.begin() + i);
            nums.insert(nums.begin(), 0);
            i++;
        }else{
          i++;
        }
    }
}

void print_ret(vector<int> &ret) {
    cout << "[  ";
    for (int i : ret) {
        cout << i << ", ";
    }
    cout << "\b\b  ]" << endl;
}

int main() {
    vector<vector<int>> testdata = {{2, 0, 2, 1, 1, 0},
                                    {2, 2, 1}};
    for (auto it : testdata) {
        print_ret(it);
        sortColors(it);
        print_ret(it);
    }
}