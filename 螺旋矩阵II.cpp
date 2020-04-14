#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int row = 0, col = 0;
    bool flag = true;
    int num = 1;
    while (flag) {
        flag = false;
        while (col != n && matrix[row][col] == 0) {
            matrix[row][col] = num++;
            col++;
            flag = true;
        }
        col--;
        row++;
        while (row != n && matrix[row][col] == 0) {

            matrix[row][col] = num++;
            row++;
            flag = true;
        }
        row--;
        col--;
        while (col != -1 && matrix[row][col] == 0) {
            matrix[row][col] = num++;
            col--;
            flag = true;
        }
        col++;
        row--;
        while (row != -1 && matrix[row][col] == 0) {
            matrix[row][col] = num++;
            row--;
            flag = true;
        }
        row++;
        col++;
    };
    return matrix;
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
    vector<int> testdata = {1, 2, 3, 4, 5, 6, 7};
    for (int i : testdata) {
        print_ret(generateMatrix(i));
    }
}