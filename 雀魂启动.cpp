#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
bool dfs(vector<int> nums) {
    for (int i = 0; i < 9; i++) {
        if (nums[i] >= 3) {
            nums[i] -= 3;
            if (dfs(nums)) {
                return true;
            }
            nums[i] += 3;
        }
    }
    for (int i = 0; i < 7; i++) {
        while (nums[i] >= 1) {
            nums[i]--;
            nums[i + 1]--;
            nums[i + 2]--;
        }
    }
    for (int i = 0; i < 9; i++) {
        if (nums[i] != 0) {
            return false;
        }
    }
    return true;
}
bool check(vector<int> nums) {
    for (int i = 0; i < 9; i++) {

        if (nums[i] < 2) {
            nums[i]--;
            continue;
        }
        nums[i] -= 2;
        if (dfs(nums)) {
            return true;
        }
        nums[i] += 2;
    }
    return false;
}
int main() {
    vector<int> nums(9, 0);
    int n;
    bool flag = false;
    for (int i = 0; i < 13; i++) {
        cin >> n;
        nums[n - 1]++;
    }
    for (int i = 0; i < 9; i++) {
        if (nums[i] == 4) {
            continue;
        }
        nums[i]++;
        if (check(nums)) {
            flag = true;
            cout << i + 1 << " ";
        }
        nums[i]--;
    }
    if (!flag) {
        cout << 0 << endl;
    }
}