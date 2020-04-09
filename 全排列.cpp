#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> ret;
    if (nums.empty()) {
        return ret;
    }
    vector<int> ans(1, nums[0]);
    ret.push_back(ans);
    if (nums.size() == 1) {
        return ret;
    }

    for (int i = 1; i < nums.size(); i++) {
        vector<vector<int>> ret_tmp;
        for (auto it : ret) {
            for (int j = 0; j <= it.size(); j++) {
                vector<int> tmp = it;
                tmp.insert(tmp.begin() + j, nums[i]);
                ret_tmp.push_back(tmp);
            }
        }
        ret = ret_tmp;
    }
    return ret;
}

void print_ret(vector<vector<int>> ret) {
    cout << "[" << endl;
    for (auto it : ret) {
        cout << "  [ ";
        for (auto i : it) {
            cout << i << ", ";
        }
        cout << "\b\b ]" << endl;
    }
    cout << "]" << endl;
}

int main() {
    vector<vector<int>> testdata = {
        {1, 2, 3},
        {4, 6, 8, 9},
    };
    for (auto it : testdata) {
        print_ret(permute(it));
    }
}