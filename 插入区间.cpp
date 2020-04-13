#include <iostream>
#include <vector>

using namespace std;

int bin_search(vector<vector<int>> &intervals, int value, bool &find) {
    int left = 0, right = intervals.size() - 1;
    int mid = (left + right) / 2;
    while (left <= right) {
        if (intervals[left][0] <= value && intervals[left][1] >= value) {
            find = true;
            return left;
        }
        if (intervals[right][0] <= value && intervals[right][1] >= value) {
            find = true;
            return right;
        }
        mid = (left + right) / 2;
        if (intervals[mid][0] <= value && intervals[mid][1] >= value) {
            find = true;
            return mid;
        }
        if (value > intervals[mid][1]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return right;
}

vector<vector<int>> insert(vector<vector<int>> &intervals,
                           vector<int> &newInterval) {
    bool find_left = false;
    int left_index = bin_search(intervals, newInterval[0], find_left);
    // cout << "find = " << find_left << " left=  " << left_index << endl;
    bool find_right = false;
    int right_index = bin_search(intervals, newInterval[1], find_right);
    // cout << "find = " << find_right << " right_index  " << right_index <<
    // endl;
    if (find_left == false) {
        if (find_right == false) {
            if (left_index + 1 <= right_index) {
                intervals.erase(intervals.begin() + (left_index + 1),
                                intervals.begin() + (right_index + 1));
            }
            intervals.insert(intervals.begin() + (left_index + 1), newInterval);
            return intervals;

        } else {
            if (left_index + 1 < right_index) {
              intervals.erase(intervals.begin() + (left_index + 1),
                              intervals.begin() + right_index);
            }
            intervals[left_index + 1][0] = newInterval[0];
            return intervals;
        }
    } else {
        if (find_right == false) {
            if (left_index + 1 <= right_index) {
                intervals.erase(intervals.begin() + left_index + 1,
                                intervals.begin() + (right_index + 1));
            }
            intervals[left_index][1] = newInterval[1];
            return intervals;
        } else {
            intervals[left_index][1] = intervals[right_index][1];
            if(left_index+1<=right_index){
              intervals.erase(intervals.begin() + (left_index + 1),
                              intervals.begin() + (right_index + 1));
            }
            return intervals;
        }
    }
}

struct testdata {
    vector<vector<int>> intervals;
    vector<int> newInterval;
};

void print_ret(vector<vector<int>> ret) {
    cout << "[  ";
    for (auto it : ret) {
        cout << "[";
        for (int i : it) {
            cout << i << ", ";
        }
        cout << "\b\b], ";
    }
    cout << "\b\b  ]" << endl;
}

int main() {
    vector<testdata> data = {
        //{{{1, 3}, {6, 9}}, {2, 5}},
        {{{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}}, {0, 11}},
        //{{{2, 7}, {8, 8}, {10, 10}, {12, 13}, {16, 19}}, {9, 17}},
    };
    for (auto d : data) {
        print_ret(insert(d.intervals, d.newInterval));
    }
}