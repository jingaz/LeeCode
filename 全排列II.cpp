#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<int>> ret;
int len;
void dfs(vector<int> ans, unordered_map<int, int> nums_map) {
    if (ans.size() == len) {
        ret.push_back(ans);
        return;
    }
    for(auto &k_v:nums_map){
        if(k_v.second>0){
          k_v.second--;
          ans.push_back(k_v.first);
          dfs(ans, nums_map);
          ans.pop_back();
          k_v.second++;
        }
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums) {
    if (nums.empty()) {
        return ret;
    }
    unordered_map<int, int> nums_map;
    for (int i : nums) {
        if (nums_map.count(i)) {
            nums_map[i]++;
        } else {
            nums_map[i] = 1;
        }
    }
    len = nums.size();
    vector<int> ans;
    dfs(ans, nums_map);
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
        //{1, 2, 3, 2, 3, 4, 5, 5, 6, 7, 6, 5},
        {1, 2, 1, 2},
    };
    for (auto it : testdata) {
        print_ret(permuteUnique(it));
    }
}