#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> ret;
vector<int> ans;

void dfs(vector<bool> &used, int index, int k) {
    if (k == 0) {
        ret.emplace_back(ans);
    }
    for (int i = index; i < used.size(); i++) {
        if (!used[i]) {
            used[i] = true;
            ans.emplace_back(i + 1);
            dfs(used, i, k - 1);
            ans.pop_back();
            used[i] = false;
        }
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<bool> used(n, false);
    dfs(used, 0, k);
    return ret;
}

void print_ret(vector<vector<int>> ret) {
    cout << "[" << endl;
    for (auto it : ret) {
        cout << "  [";
        for (auto i : it) {
            cout << i << ", ";
        }
        cout << "\b\b]" << endl;
    }
    cout << "]" << endl;
}

int main() {
    vector<pair<int, int>> testdata = {
        {4, 2},
        {1, 1},
        {8, 4},
    };
    for (auto &i : testdata) {
        ret.clear();
        ans.clear();
        print_ret(combine(i.first, i.second));
    }
}