#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ret;
vector<int> ans;
void dfs(vector<int> &nums, vector<bool> &used, int index) {
    ret.emplace_back(ans);
    for (int i = index; i < used.size(); i++) {
        if (!used[i]) {
            if (i > 0 && !used[i - 1] && nums[i - 1] == nums[i]) {
                continue;
            }
            used[i] = true;
            ans.emplace_back(nums[i]);
            dfs(nums, used, i);
            ans.pop_back();
            used[i] = false;
        }
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<bool> used(nums.size(), false);
    dfs(nums, used, 0);
    return ret;
}
void print_ret(vector<vector<int>> ret) {
    cout << "[" << endl;
    for (auto it : ret) {
        cout << "  [  ";
        for (auto i : it) {
            cout << i << ", ";
        }
        cout << "\b\b  ]" << endl;
    }
    cout << "]" << endl;
}
int main() {
    vector<vector<int>> testdata = {
        {1, 2, 2},
        {1, 3, 3, 7, 7},
        {4},
        {0,0,0,0,0}
    };
    for (auto &i : testdata) {
        ret.clear();
        ans.clear();
        print_ret(subsetsWithDup(i));
    }
}