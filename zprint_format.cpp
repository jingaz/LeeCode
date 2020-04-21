#include <iostream>
#include <vector>
using namespace std;

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
