#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int removeElement(vector<int> &nums, int val) {
    while (true) {
        vector<int>::iterator it = find(nums.begin(), nums.end(), val);
        if (it != nums.end()) {
          nums.erase(it);
        } else {
            break;
        }
    }
    return nums.size();
}

void print_array(vector<int> &nums, int n) {
    cout << "[ ";
    for (int i = 0; i < n; i++) {
        cout << nums[i] << ", ";
    }
    cout << "\b\b ]" << endl;
}
int main() {
    vector<vector<int>> testdata = {
        {3, 2, 2, 3},
        {0, 0, 1, 1, 1, 2, 2, 3, 3, 4},
    };
    for (vector<int> it : testdata) {
        print_array(it, removeElement(it, 3));
    }
}
