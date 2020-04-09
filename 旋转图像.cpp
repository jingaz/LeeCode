#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


void rotate(vector<vector<int>> &matrix) {
    if (matrix.empty()) {
        return;
    }
    int n = matrix.size();
    int max_pos = (n+1)/2;
    for (int i = 0; i < max_pos; i++) {
      for (int j = i;j< n-i-1;j++){
        int x = i, y = j;
        int tmp1=matrix[x][y];
        for (int count = 0; count < 4; count++) {
          int next_x = y;
          int next_y = n - 1 - x;
          int tmp2 = matrix[next_x][next_y];
          matrix[next_x][next_y] = tmp1;
          x = next_x;
          y = next_y;
          tmp1 = tmp2;
        }
      }
    }
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
    vector<vector<vector<int>>> testdata = {
        {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
        {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}},
    };
    for (auto &it : testdata) {
        rotate(it);
        print_ret(it);
    }
}