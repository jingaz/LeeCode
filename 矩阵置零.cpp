#include <iostream>
#include <vector>
using namespace std;
void setZeroes(vector<vector<int>> &matrix) {
    int M = matrix.size();
    int N = matrix.back().size();
    if (N * N == 0) {
        return;
    }
    bool row_flag = false, col_flag = false;
    for (int i = 0; i < M; i++) {
        if (matrix[i][0] == 0) {
            col_flag = true;
            break;
        }
    }
    for (int j = 0; j < N; j++) {
        if (matrix[0][j] == 0) {
            row_flag = true;
            break;
        }
    }
    for (int i = 1; i < M; i++) {
        for (int j = 1; j < N; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < M; i++) {
        if (matrix[i][0] == 0) {
            for (int j = 0; j < N; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    for (int j = 1; j < N; j++) {
        if (matrix[0][j] == 0) {
            for (int i = 0; i < M; i++) {
                matrix[i][j] = 0;
            }
        }
    }
    if (col_flag) {
        for (int i = 0; i < M; i++) {
            matrix[i][0] = 0;
        }
    }
    if (row_flag) {
        for (int j = 0; j < N; j++) {
            matrix[0][j] = 0;
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
        //{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}},
        //{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}},
        {{1, 0}}};

    for (auto it : testdata) {
        cout << "before:" << endl;
        print_ret(it);
        setZeroes(it);
        cout << "after:" << endl;
        print_ret(it);
    }
}
