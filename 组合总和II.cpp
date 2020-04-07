#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int> &candidates, int left, int len, int target,
         vector<vector<int>> &ret, vector<int> &ans) {
    if (target == 0) {
        ret.push_back(ans);
    }
    for (int i = left; i < len; i++) {
        if (candidates[i] > target) {
            return;
        }
        if (i > left && candidates[i] == candidates[i - 1]) {
            continue;
        }
        ans.push_back(candidates[i]);
        dfs(candidates, i + 1, len, target - candidates[i], ret, ans);
        ans.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> ret;
    sort(candidates.begin(), candidates.end());
    if (target < candidates.front()) {
        return ret;
    }
    vector<int> ans;
    dfs(candidates, 0, candidates.size(), target, ret, ans);
    return ret;
}

struct testdata {
    vector<int> candidates;
    int target;
};
void print_ret(vector<vector<int>> ret) {
    cout << "answer:" << endl;
    for (auto i : ret) {
        cout << "[ ";
        for (auto j : i) {
            cout << j << ", ";
        }
        cout << "\b\b ]" << endl;
    }
}
int main() {
    vector<testdata> data = {
        {{10, 1, 2, 7, 6, 1, 5}, 8},
        {{2, 5, 2, 1, 2}, 5},
    };
    for (auto i : data) {
        print_ret(combinationSum2(i.candidates, i.target));
    }
}