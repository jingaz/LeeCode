#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> result(vector<int> &candidates, int pos, int target) {
    vector<vector<int>> ret;
    if (target <= 0 || pos < 0) {
        return ret;
    }
    int max_num = 0;
    int count = 0;
    while (max_num < target) {
        vector<vector<int>> ret_pre =
            result(candidates, pos - 1, target - max_num);
        if (!ret_pre.empty()) {
            for (auto &it : ret_pre) {
                for (int i = 0; i < count; i++) {
                    it.push_back(candidates[pos]);
                }
            }
            for (auto it : ret_pre) {
                ret.push_back(it);
            }
        }
        count++;
        max_num += candidates[pos];
    }
    if (max_num == target) {
        vector<int> tmp;
        while (count > 0) {
            tmp.push_back(candidates[pos]);
            count--;
        }
        ret.push_back(tmp);
    }
    return ret;
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> ret;
    sort(candidates.begin(), candidates.end());
    if (target < candidates.front()) {
        return ret;
    }

    int left = 0, right = candidates.size() - 1;
    int pos = 0;
    while (left <= right) {
        pos = (left + left) / 2;
        if (candidates[pos] == target) {
            break;
        }
        if (candidates[left] == target) {
            pos = left;
            break;
        }
        if (candidates[right] == target) {
            pos = right;
            break;
        }
        if (candidates[pos] > target) {
            right = pos - 1;
        } else {
            left = pos + 1;
        }
    }
    return result(candidates, pos, target);
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
        {{2, 3, 4, 6, 7, 8, 9, 12, 13, 14, 15, 16}, 12},
        {{2, 3, 5}, 8},
    };
    for (auto i : data) {
        print_ret(combinationSum(i.candidates, i.target));
    }
}