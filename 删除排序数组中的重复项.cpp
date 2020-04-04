#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int removeDuplicates(vector<int> &nums) { 
    sort(nums.begin(), nums.end());
    vector<int>::iterator iter=unique(nums.begin(),nums.end());
    return iter - nums.begin();
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
        {1, 1, 2},
        {0, 0, 1, 1, 1, 2, 2, 3, 3, 4},
    };
    for (vector<int> it : testdata) {
        print_array(it, removeDuplicates(it));
    }
}
