#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> ans;
    int N = matrix.size();
    if (N == 0)
        return ans;
    int M = matrix.front().size();
    if (M == 0)
        return ans;
    vector<vector<int>> tmp(N, vector<int>(M, 0));
    int row = 0, col = 0;
    bool flag = true;
    while (flag) {
        flag = false;
        while (col != M && tmp[row][col] != 1) {
            ans.push_back(matrix[row][col]);
            tmp[row][col] = 1;
            col++;
            flag = true;
        }
        col--;
        row++;
        while (row != N && tmp[row][col] != 1) {
            ans.push_back(matrix[row][col]);
            tmp[row][col] = 1;
            row++;
            flag = true;
        }
        row--;
        col--;
        while (col != -1 && tmp[row][col] != 1) {
            ans.push_back(matrix[row][col]);
            tmp[row][col] = 1;
            col--;
            flag = true;
        }
        col++;
        row--;
        while (row != -1 && tmp[row][col] != 1) {
            ans.push_back(matrix[row][col]);
            tmp[row][col] = 1;
            row--;
            flag = true;
        }
        row++;
        col++;
    };
    return ans;
}

void print_ret(vector<int> ret) {
    cout << "[ ";
    for (int i : ret) {
        cout << i << ", ";
    }
    cout << "\b\b ]" << endl;
}

int main() {
    vector<vector<vector<int>>> testdata = {
        //{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
        {{1}},
    };
    for (auto it : testdata) {
        print_ret(spiralOrder(it));
    }
}