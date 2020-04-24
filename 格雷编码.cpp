#include <iostream>
#include <vector>
using namespace std;
vector<int> grayCode(int n) {
    vector<int> ret;
    for (int i = 0; i < 1 << n; i++) {
        ret.emplace_back(i ^ i >> 1);
    }
    return ret;
}

void print_ret(vector<int> ret) {
    cout << "[  ";
    for (auto i : ret) {
        cout << i << ", ";
    }
    cout << "\b\b  ]" << endl;
}

int main() {
    vector<int> data = {0, 1, 2, 3, 4};
    for (auto &it : data) {
        print_ret(grayCode(it));
    }
}