#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> &digits) {
    for (int i = digits.size() - 1; i >= 0; i--) {
        digits[i]++;
        if (digits[i] == 10) {
            digits[i] = 0;
            if (i == 0) {
                digits.insert(digits.begin(), 1);
            }
        } else {
            return digits;
        }
    }
    return digits;
}

void print_ret(vector<int> ret) {
    cout << "[  ";
    for (int i : ret) {
        cout << i << ", ";
    }
    cout << "\b\b  ]" << endl;
}

int main() {
    vector<vector<int>> testdata = {
        {1, 2, 3},
        {0},
        {9, 9, 9, 9},
    };
    for (auto it : testdata) {
        print_ret(plusOne(it));
    }
}