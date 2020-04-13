#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](auto &a, auto &b) { return a[0] < b[0]; });
    if (intervals.size() < 2) {
        return intervals;
    }
    vector<vector<int>> ret;
    for (int i = 0; i < intervals.size() - 1; i++) {
        int &pre_a = intervals[i].front();
        int &pre_b = intervals[i].back();
        int &next_a = intervals[i + 1].front();
        int &next_b = intervals[i + 1].back();
        if (pre_b < next_a) {
            ret.push_back(intervals[i]);
        } else {
            next_a = pre_a;
            next_b = max(pre_b, next_b);
        }
    }
    ret.push_back(intervals.back());
    return ret;
}
void print_ret(vector<vector<int>> ret) {
    cout << "[ ";
    for (auto it : ret) {
        cout << "[";
        for (int i : it) {
            cout << i << ", ";
        }
        cout << "\b\b], ";
    }
    cout << "\b\b ]" << endl;
}

int main() {
    vector<vector<vector<int>>> testdata = {
        {{1, 3}, {8, 10}, {2, 6}, {15, 18}},
        {{1,4},{4,5}},
    };
    for (auto it : testdata) {
        print_ret(merge(it));
    }
}