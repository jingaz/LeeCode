#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int search(vector<int> &nums, int target) {
    int ans = -1;
    if (nums.size <= 3) {
        for (int i = 0; i < nums.size(); i++) {
            ans = nums[i] == target ? i : ans;
        }
        return ans;
    }

    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if(nums[mid]>target&&nums[left]>target){
          left = mid;
        }

    }
    return ans;
}

struct testdata {
    vector<int> num_array;
    int target;
};

int main() {
    vector<testdata> data = {
        {{4, 5, 6, 7, 0, 1, 2}, 0},
        {{4, 5, 6, 7, 0, 1, 2}, 3},
    };
    for (testdata i : data) {
        cout << search(i.num_array, i.target) << endl;
    }
}