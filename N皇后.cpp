#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<vector<string>> ret;
int N;
void purge(vector<string> &ans) {
    for (string &str : ans) {
        for (char &a : str) {
            if (a == 'X') {
                a = '.';
            }
        }
    }
}
void set_pos(int r, int c, vector<string> &ans) {
    ans[r][c] = 'Q';
    // 修改左下角
    for (int row_n = r + 1, col_n = c - 1; row_n < N && col_n >= 0;
         row_n++, col_n--) {
        ans[row_n][col_n] = 'X';
    }
    // 修改正下方
    for (int row_n = r + 1; row_n < N; row_n++) {
        ans[row_n][c] = 'X';
    }
    // 修改右下方
    for (int row_n = r + 1, col_n = c + 1; row_n < N && col_n < N;
         row_n++, col_n++) {
        ans[row_n][col_n] = 'X';
    }
}

void dfs(int row, vector<string> &ans) {
    if (row == N) {
        vector<string> tmp = ans;
        purge(tmp);
        ret.push_back(tmp);
        return;
    }

    for (int col = 0; col < N; col++) {
        if (ans[row][col] == '.') {
            vector<string> tmp_ans = ans;
            set_pos(row, col, tmp_ans);
            dfs(row + 1, tmp_ans);
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    N = n;
    vector<string> ans(n, string(N, '.'));

    if (N <= 0)
        return ret;
    if (N == 1) {
        return vector<vector<string>>(1, vector<string>(1, "Q"));
    }
    for (int j = 0; j < N; j++) {
        vector<string> tmp = ans;
        set_pos(0, j, tmp);
        dfs(1, tmp);
    }
    return ret;
}

void print_ret(vector<vector<string>> ret) {
    for (auto ans : ret) {
        cout << "[" << endl;
        for (auto i : ans) {
            cout << " " << i << endl;
        }
        cout << "]" << endl;
    }
}

int main() {
    vector<int> testdata = {1, 2, 4, 8};
    for (int i : testdata) {
        cout << "n = " << i << endl;
        print_ret(solveNQueens(i));
        ret.clear();
    }
}